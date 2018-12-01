PROG=		softintdump
SRCS=		softintdump.c ksyms_subr.c

CFLAGS+=	-D_KMEMUSER -I${BSDSRCDIR}/sys
LDADD+=		-lkvm
DPADD+=	
NOMAN=		yes

BINDIR=		/usr/local/bin

DPSRCS+=	softint.h
CLEANFILES+=	softint.h

softint.h:
	sed -n '/typedef struct softint/,/softcpu_t/p' ${BSDSRCDIR}/sys/kern/kern_softint.c > softint.h

.include <bsd.prog.mk>
