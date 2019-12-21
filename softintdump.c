#include <err.h>
#include <fcntl.h>
#include <kvm.h>
#include <limits.h>
#include <nlist.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

#include <sys/cpu_data.h>
#include <sys/evcnt.h>
#include <sys/intr.h>
#include <sys/param.h>
#include <sys/proc.h>
#include <sys/queue.h>
#include <sys/sysctl.h>

#include "ksyms_subr.h"
#include "softint.h"

//#define DEBUG


kvm_t *kd;


enum {
	NLST_CPUINFOS = 0,
	NLST_SOFTINT_BYTES,
	NLST_MAX
};

struct nlist nlst[] = {
	[NLST_CPUINFOS]		=	{ .n_name = "_cpu_infos" },
	[NLST_SOFTINT_BYTES]	=	{ .n_name = "_softint_bytes" },
	[NLST_MAX]		=	{ .n_name = NULL }
};


#define MAXCPUINFOS	32
struct cpu_info *cpu_infos[MAXCPUINFOS];

u_int softint_bytes;
u_int softint_max;
unsigned long pagesize;
#define ROUND_PAGE(x)	\
	(((unsigned long)(x) + (pagesize - 1)) / pagesize * pagesize)

#define CPUDATA_OFFSET_MAX	512

int
main(int argc, char *argv[])
{
	struct kinfo_proc2 *kinfo;
	struct proc procbuf;
	struct lwp lwpbuf, *curlwp;
	int nentries;
	ssize_t size;
	size_t cpudata_offset;
	void *cpu_infos_ptr;
	char errbuf[_POSIX2_LINE_MAX];
	char buf[1024];
	int cpuno, softintno, i;
	void *ptr;
	struct cpu_data cpudata;

	ksyms_load();

#ifdef DEBUG
	printf("sizeof cpudata = %u\n", sizeof(struct cpu_data));
	printf("sizeof proc = %u\n", sizeof(struct proc));
	printf("sizeof lwp = %u\n", sizeof(struct lwp));
	printf("sizeof struct softhand = %u\n", sizeof(softhand_t));
#endif

	pagesize = getpagesize();

	kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "softintdump");
	if (kd == NULL)
		exit(EX_NOINPUT);

	kinfo = kvm_getproc2(kd, KERN_PROC_PID, getpid(), sizeof(struct kinfo_proc2), &nentries);
	if (nentries != 1)
		err(EX_NOINPUT, "kvm_getproc2");

#ifdef DEBUG
	printf("nentries=%d\n", nentries);
	printf("kinfo = %p\n", kinfo);
	printf("proc= %p\n", kinfo->p_paddr);
#endif

	size = kvm_read(kd, kinfo->p_paddr, &procbuf, sizeof(struct proc));
	if (size == -1)
		err(EX_IOERR, "kvm_read");
#ifdef DEBUG
	printf("size = %lld\n", size);
#endif

	curlwp = LIST_FIRST(&procbuf.p_lwps);
#ifdef DEBUG
	printf("curlwp = %p\n", curlwp);
#endif

	size = kvm_read(kd, (unsigned long)curlwp, &lwpbuf, sizeof(struct lwp));
	if (size == -1)
		err(EX_IOERR, "kvm_read");
#ifdef DEBUG
	printf("size = %lld\n", size);
#endif

	nentries = kvm_nlist(kd, nlst);
	if (nentries < 0)
		err(1, "kvm_nlist");

#ifdef DEBUG
	printf("cpu_infos     = %016lx\n", nlst[NLST_CPUINFOS].n_value);
	printf("softint_bytes = %016lx\n", nlst[NLST_SOFTINT_BYTES].n_value);
#endif

	kvm_read(kd, nlst[NLST_CPUINFOS].n_value, &cpu_infos_ptr, sizeof(cpu_infos_ptr));
	if (size == -1)
		err(EX_IOERR, "kvm_read");
#ifdef DEBUG
	printf("*cpu_infos[] = %p\n", cpu_infos_ptr);
#endif

	kvm_read(kd, nlst[NLST_SOFTINT_BYTES].n_value, &softint_bytes, sizeof(softint_bytes));
	if (size == -1)
		err(EX_IOERR, "kvm_read");

#ifdef DEBUG
	printf("*softint_bytes = %u (%u)\n", softint_bytes, ROUND_PAGE(softint_bytes));
#endif
	softint_bytes = ROUND_PAGE(softint_bytes);
	softint_max = (softint_bytes - sizeof(softcpu_t)) / sizeof(softhand_t);

	kvm_read(kd, (unsigned long)cpu_infos_ptr, cpu_infos, sizeof(cpu_infos));
	if (size == -1)
		err(EX_IOERR, "kvm_read");

	for (cpuno = 0; cpuno < MAXCPUINFOS; cpuno++) {
		char cpu_name[8];
		snprintf(cpu_name, sizeof(cpu_name), "cpu%d", cpuno);

		if (cpu_infos[cpuno] == 0)
			continue;

#ifdef DEBUG
		printf("cpu_info[%d] = %016lx\n", cpuno, cpu_infos[cpuno]);
#endif

		for (cpudata_offset = 0; cpudata_offset < CPUDATA_OFFSET_MAX; cpudata_offset += sizeof(void *)) {
			size = kvm_read(kd,
			    (unsigned long)cpu_infos[cpuno] + cpudata_offset,
			    &cpudata, sizeof(struct cpu_data));
			if (size == -1)
				err(EX_IOERR, "kvm_read");

			if (strcmp(cpudata.cpu_name, cpu_name) == 0)
				goto found;
		}
	}

	fprintf(stderr, "cannot found cpu_data\n");
	exit(1);

found:

	for (cpuno = 0; cpuno < MAXCPUINFOS; cpuno++) {
		softcpu_t softcpu;
		softhand_t softhand;
		softint_t softint;
		unsigned long softhandp;

		if (cpu_infos[cpuno] == 0)	/* no CPU info */
			continue;

		/* read cpu_info */
		size = kvm_read(kd,
		    (unsigned long)cpu_infos[cpuno] + cpudata_offset,
		    &cpudata, sizeof(struct cpu_data));
		if (size == -1)
			err(EX_IOERR, "kvm_read");
#ifdef DEBUG
		printf("cpu_info[%d].cpu_softcpu = %p\n", cpuno, cpudata.cpu_softcpu);
#endif

		/* read softcpu_t from cpuinfo->cpu_softcpu */
		size = kvm_read(kd, (unsigned long)cpudata.cpu_softcpu,
		    &softcpu, sizeof(softcpu));
		if (size == -1)
			err(EX_IOERR, "kvm_read");


		/* dump sc_hand[] array */
		for (i = 0, softhandp = ((unsigned long)cpudata.cpu_softcpu + offsetof(struct softcpu, sc_hand[0]));
		    i < softint_max;
		    i++, softhandp += sizeof(softhand_t)) {

			size = kvm_read(kd, softhandp,
			    &softhand, sizeof(softhand));
			if (size == -1) {
				printf("kvm_read: %s\n", kvm_geterr(kd));
				break;
			}

			memset(&softint, 0, sizeof(softint));
			if (softhand.sh_isr != NULL) {
				size = kvm_read(kd, (unsigned long)softhand.sh_isr,
				    &softint, sizeof(softint));
				if (size == -1) {
					printf("kvm_read: %s\n", kvm_geterr(kd));
				}
			}

			if (i != 0 &&
			    softhand.sh_func == NULL &&
			    softhand.sh_arg == 0 &&
			    softhand.sh_isr == 0)
				continue;

#ifdef DEBUG
			printf("kvm:%016llx: ", softhandp);
#endif

			printf("CPU%d: ", cpuno);

			printf("sc_hand[%3d/%d].sh_func=%016lx %-32s  .arg=%018p  .sh_isr=%p [%s][%s]\n", i, softint_max,
			    (unsigned long)softhand.sh_func,
			    ksyms_lookupsym((unsigned long)softhand.sh_func),
			    softhand.sh_arg,
			    softhand.sh_isr,
			    softint.si_name,
			    softint.si_name_block);
		}

		printf("\n");

	}
}
