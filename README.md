# softintdump

softintdump is a program to display the softint(9) handler tables of the NetBSD kernel.
Since it refers directly to the kernel memory via /dev/kmem, root privileges are required.


# build
To build, you need the NetBSD source tree. In particular, /usr/src/sys/kern/kern_softint.c must be from a running kernel. See the Makefile for details.


# see also
- https://man.netbsd.org/softint.9
- https://man.netbsd.org/kmem.9
- https://nxr.netbsd.org/xref/src/sys/kern/kern_softint.c
- https://nxr.netbsd.org/search?q=cpu_softcpu&project=src&defs=&refs=&path=&hist=

# example
	# sudo softintdump
	CPU0: sc_hand[  1/799].sh_func=ffffffc0004bf070 arpintr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[  2/799].sh_func=ffffffc0003d8c40 callout_softclock                 .arg=0x0000000000000000  .sh_isr=0xffffffc062a100c0 [clk/0][clk block/0]
	CPU0: sc_hand[  3/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062a10178 [ser/0][ser block/0]
	CPU0: sc_hand[  4/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[  5/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062a10008 [bio/0][bio block/0]
	CPU0: sc_hand[  6/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062a100c0 [clk/0][clk block/0]
	CPU0: sc_hand[  7/799].sh_func=ffffffc0003d6548 timer_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062a100c0 [clk/0][clk block/0]
	CPU0: sc_hand[  8/799].sh_func=ffffffc0003f1328 logsoftintr                       .arg=0x0000000000000000  .sh_isr=0xffffffc062a100c0 [clk/0][clk block/0]
	CPU0: sc_hand[  9/799].sh_func=ffffffc000418000 ttysigintr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062a100c0 [clk/0][clk block/0]
	CPU0: sc_hand[ 10/799].sh_func=ffffffc000439838 biointr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062a10008 [bio/0][bio block/0]
	CPU0: sc_hand[ 11/799].sh_func=ffffffc0004a7998 pppoe_softintr_handler            .arg=0x0000000000000000  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 12/799].sh_func=ffffffc00003f5c8 plcomsoft                         .arg=0xffff0000ff2d6c68  .sh_isr=0xffffffc062a10178 [ser/0][ser block/0]
	CPU0: sc_hand[ 13/799].sh_func=ffffffc0004f2fe0 vioif_rx_softint                  .arg=0xffff0000fee49008  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 14/799].sh_func=ffffffc0004f2fb8 vioif_ctl_softint                 .arg=0xffff0000fee49008  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 15/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fee49248  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 16/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb748  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 17/799].sh_func=ffffffc00047ceb8 if_deferred_start_softint         .arg=0xffff0000ff2bb768  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 18/799].sh_func=ffffffc0001a4640 cprng_fast_intr                   .arg=0x0000000000000000  .sh_isr=0xffffffc062a10178 [ser/0][ser block/0]
	CPU0: sc_hand[ 19/799].sh_func=ffffffc0003c33b0 rnd_intr                          .arg=0x0000000000000000  .sh_isr=0xffffffc062a10178 [ser/0][ser block/0]
	CPU0: sc_hand[ 20/799].sh_func=ffffffc0003c2b60 rnd_wake                          .arg=0x0000000000000000  .sh_isr=0xffffffc062a100c0 [clk/0][clk block/0]
	CPU0: sc_hand[ 21/799].sh_func=ffffffc0001de420 ipintr                            .arg=0x0000000000000000  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 22/799].sh_func=ffffffc000210778 ip6intr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 23/799].sh_func=ffffffc0004b1eb0 route_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 24/799].sh_func=ffffffc00019cd80 cryptointr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 25/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb908  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 26/799].sh_func=ffffffc00019b618 cryptoret_softint                 .arg=0x0000000000000000  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 27/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fe4be418  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	CPU0: sc_hand[ 28/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bbba8  .sh_isr=0xffffffc062a10230 [net/0][net block/0]
	
	CPU1: sc_hand[  1/799].sh_func=ffffffc0004bf070 arpintr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[  2/799].sh_func=ffffffc0003d8c40 callout_softclock                 .arg=0x0000000000000000  .sh_isr=0xffffffc062a880c0 [clk/1][clk block/1]
	CPU1: sc_hand[  3/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062a88178 [ser/1][ser block/1]
	CPU1: sc_hand[  4/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[  5/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062a88008 [bio/1][bio block/1]
	CPU1: sc_hand[  6/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062a880c0 [clk/1][clk block/1]
	CPU1: sc_hand[  7/799].sh_func=ffffffc0003d6548 timer_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062a880c0 [clk/1][clk block/1]
	CPU1: sc_hand[  8/799].sh_func=ffffffc0003f1328 logsoftintr                       .arg=0x0000000000000000  .sh_isr=0xffffffc062a880c0 [clk/1][clk block/1]
	CPU1: sc_hand[  9/799].sh_func=ffffffc000418000 ttysigintr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062a880c0 [clk/1][clk block/1]
	CPU1: sc_hand[ 10/799].sh_func=ffffffc000439838 biointr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062a88008 [bio/1][bio block/1]
	CPU1: sc_hand[ 11/799].sh_func=ffffffc0004a7998 pppoe_softintr_handler            .arg=0x0000000000000000  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 12/799].sh_func=ffffffc00003f5c8 plcomsoft                         .arg=0xffff0000ff2d6c68  .sh_isr=0xffffffc062a88178 [ser/1][ser block/1]
	CPU1: sc_hand[ 13/799].sh_func=ffffffc0004f2fe0 vioif_rx_softint                  .arg=0xffff0000fee49008  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 14/799].sh_func=ffffffc0004f2fb8 vioif_ctl_softint                 .arg=0xffff0000fee49008  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 15/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fee49248  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 16/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb748  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 17/799].sh_func=ffffffc00047ceb8 if_deferred_start_softint         .arg=0xffff0000ff2bb768  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 18/799].sh_func=ffffffc0001a4640 cprng_fast_intr                   .arg=0x0000000000000000  .sh_isr=0xffffffc062a88178 [ser/1][ser block/1]
	CPU1: sc_hand[ 19/799].sh_func=ffffffc0003c33b0 rnd_intr                          .arg=0x0000000000000000  .sh_isr=0xffffffc062a88178 [ser/1][ser block/1]
	CPU1: sc_hand[ 20/799].sh_func=ffffffc0003c2b60 rnd_wake                          .arg=0x0000000000000000  .sh_isr=0xffffffc062a880c0 [clk/1][clk block/1]
	CPU1: sc_hand[ 21/799].sh_func=ffffffc0001de420 ipintr                            .arg=0x0000000000000000  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 22/799].sh_func=ffffffc000210778 ip6intr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 23/799].sh_func=ffffffc0004b1eb0 route_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 24/799].sh_func=ffffffc00019cd80 cryptointr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 25/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb908  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 26/799].sh_func=ffffffc00019b618 cryptoret_softint                 .arg=0x0000000000000000  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 27/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fe4be418  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	CPU1: sc_hand[ 28/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bbba8  .sh_isr=0xffffffc062a88230 [net/1][net block/1]
	
	CPU2: sc_hand[  1/799].sh_func=ffffffc0004bf070 arpintr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[  2/799].sh_func=ffffffc0003d8c40 callout_softclock                 .arg=0x0000000000000000  .sh_isr=0xffffffc062ac00c0 [clk/2][clk block/2]
	CPU2: sc_hand[  3/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0178 [ser/2][ser block/2]
	CPU2: sc_hand[  4/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[  5/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0008 [bio/2][bio block/2]
	CPU2: sc_hand[  6/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062ac00c0 [clk/2][clk block/2]
	CPU2: sc_hand[  7/799].sh_func=ffffffc0003d6548 timer_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062ac00c0 [clk/2][clk block/2]
	CPU2: sc_hand[  8/799].sh_func=ffffffc0003f1328 logsoftintr                       .arg=0x0000000000000000  .sh_isr=0xffffffc062ac00c0 [clk/2][clk block/2]
	CPU2: sc_hand[  9/799].sh_func=ffffffc000418000 ttysigintr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062ac00c0 [clk/2][clk block/2]
	CPU2: sc_hand[ 10/799].sh_func=ffffffc000439838 biointr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0008 [bio/2][bio block/2]
	CPU2: sc_hand[ 11/799].sh_func=ffffffc0004a7998 pppoe_softintr_handler            .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 12/799].sh_func=ffffffc00003f5c8 plcomsoft                         .arg=0xffff0000ff2d6c68  .sh_isr=0xffffffc062ac0178 [ser/2][ser block/2]
	CPU2: sc_hand[ 13/799].sh_func=ffffffc0004f2fe0 vioif_rx_softint                  .arg=0xffff0000fee49008  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 14/799].sh_func=ffffffc0004f2fb8 vioif_ctl_softint                 .arg=0xffff0000fee49008  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 15/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fee49248  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 16/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb748  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 17/799].sh_func=ffffffc00047ceb8 if_deferred_start_softint         .arg=0xffff0000ff2bb768  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 18/799].sh_func=ffffffc0001a4640 cprng_fast_intr                   .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0178 [ser/2][ser block/2]
	CPU2: sc_hand[ 19/799].sh_func=ffffffc0003c33b0 rnd_intr                          .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0178 [ser/2][ser block/2]
	CPU2: sc_hand[ 20/799].sh_func=ffffffc0003c2b60 rnd_wake                          .arg=0x0000000000000000  .sh_isr=0xffffffc062ac00c0 [clk/2][clk block/2]
	CPU2: sc_hand[ 21/799].sh_func=ffffffc0001de420 ipintr                            .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 22/799].sh_func=ffffffc000210778 ip6intr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 23/799].sh_func=ffffffc0004b1eb0 route_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 24/799].sh_func=ffffffc00019cd80 cryptointr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 25/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb908  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 26/799].sh_func=ffffffc00019b618 cryptoret_softint                 .arg=0x0000000000000000  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 27/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fe4be418  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	CPU2: sc_hand[ 28/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bbba8  .sh_isr=0xffffffc062ac0230 [net/2][net block/2]
	
	CPU3: sc_hand[  1/799].sh_func=ffffffc0004bf070 arpintr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[  2/799].sh_func=ffffffc0003d8c40 callout_softclock                 .arg=0x0000000000000000  .sh_isr=0xffffffc062af80c0 [clk/3][clk block/3]
	CPU3: sc_hand[  3/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062af8178 [ser/3][ser block/3]
	CPU3: sc_hand[  4/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[  5/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062af8008 [bio/3][bio block/3]
	CPU3: sc_hand[  6/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062af80c0 [clk/3][clk block/3]
	CPU3: sc_hand[  7/799].sh_func=ffffffc0003d6548 timer_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062af80c0 [clk/3][clk block/3]
	CPU3: sc_hand[  8/799].sh_func=ffffffc0003f1328 logsoftintr                       .arg=0x0000000000000000  .sh_isr=0xffffffc062af80c0 [clk/3][clk block/3]
	CPU3: sc_hand[  9/799].sh_func=ffffffc000418000 ttysigintr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062af80c0 [clk/3][clk block/3]
	CPU3: sc_hand[ 10/799].sh_func=ffffffc000439838 biointr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062af8008 [bio/3][bio block/3]
	CPU3: sc_hand[ 11/799].sh_func=ffffffc0004a7998 pppoe_softintr_handler            .arg=0x0000000000000000  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 12/799].sh_func=ffffffc00003f5c8 plcomsoft                         .arg=0xffff0000ff2d6c68  .sh_isr=0xffffffc062af8178 [ser/3][ser block/3]
	CPU3: sc_hand[ 13/799].sh_func=ffffffc0004f2fe0 vioif_rx_softint                  .arg=0xffff0000fee49008  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 14/799].sh_func=ffffffc0004f2fb8 vioif_ctl_softint                 .arg=0xffff0000fee49008  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 15/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fee49248  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 16/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb748  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 17/799].sh_func=ffffffc00047ceb8 if_deferred_start_softint         .arg=0xffff0000ff2bb768  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 18/799].sh_func=ffffffc0001a4640 cprng_fast_intr                   .arg=0x0000000000000000  .sh_isr=0xffffffc062af8178 [ser/3][ser block/3]
	CPU3: sc_hand[ 19/799].sh_func=ffffffc0003c33b0 rnd_intr                          .arg=0x0000000000000000  .sh_isr=0xffffffc062af8178 [ser/3][ser block/3]
	CPU3: sc_hand[ 20/799].sh_func=ffffffc0003c2b60 rnd_wake                          .arg=0x0000000000000000  .sh_isr=0xffffffc062af80c0 [clk/3][clk block/3]
	CPU3: sc_hand[ 21/799].sh_func=ffffffc0001de420 ipintr                            .arg=0x0000000000000000  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 22/799].sh_func=ffffffc000210778 ip6intr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 23/799].sh_func=ffffffc0004b1eb0 route_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 24/799].sh_func=ffffffc00019cd80 cryptointr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 25/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb908  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 26/799].sh_func=ffffffc00019b618 cryptoret_softint                 .arg=0x0000000000000000  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 27/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fe4be418  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	CPU3: sc_hand[ 28/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bbba8  .sh_isr=0xffffffc062af8230 [net/3][net block/3]
	
	CPU4: sc_hand[  1/799].sh_func=ffffffc0004bf070 arpintr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[  2/799].sh_func=ffffffc0003d8c40 callout_softclock                 .arg=0x0000000000000000  .sh_isr=0xffffffc062b300c0 [clk/4][clk block/4]
	CPU4: sc_hand[  3/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062b30178 [ser/4][ser block/4]
	CPU4: sc_hand[  4/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[  5/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062b30008 [bio/4][bio block/4]
	CPU4: sc_hand[  6/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062b300c0 [clk/4][clk block/4]
	CPU4: sc_hand[  7/799].sh_func=ffffffc0003d6548 timer_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062b300c0 [clk/4][clk block/4]
	CPU4: sc_hand[  8/799].sh_func=ffffffc0003f1328 logsoftintr                       .arg=0x0000000000000000  .sh_isr=0xffffffc062b300c0 [clk/4][clk block/4]
	CPU4: sc_hand[  9/799].sh_func=ffffffc000418000 ttysigintr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062b300c0 [clk/4][clk block/4]
	CPU4: sc_hand[ 10/799].sh_func=ffffffc000439838 biointr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062b30008 [bio/4][bio block/4]
	CPU4: sc_hand[ 11/799].sh_func=ffffffc0004a7998 pppoe_softintr_handler            .arg=0x0000000000000000  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 12/799].sh_func=ffffffc00003f5c8 plcomsoft                         .arg=0xffff0000ff2d6c68  .sh_isr=0xffffffc062b30178 [ser/4][ser block/4]
	CPU4: sc_hand[ 13/799].sh_func=ffffffc0004f2fe0 vioif_rx_softint                  .arg=0xffff0000fee49008  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 14/799].sh_func=ffffffc0004f2fb8 vioif_ctl_softint                 .arg=0xffff0000fee49008  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 15/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fee49248  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 16/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb748  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 17/799].sh_func=ffffffc00047ceb8 if_deferred_start_softint         .arg=0xffff0000ff2bb768  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 18/799].sh_func=ffffffc0001a4640 cprng_fast_intr                   .arg=0x0000000000000000  .sh_isr=0xffffffc062b30178 [ser/4][ser block/4]
	CPU4: sc_hand[ 19/799].sh_func=ffffffc0003c33b0 rnd_intr                          .arg=0x0000000000000000  .sh_isr=0xffffffc062b30178 [ser/4][ser block/4]
	CPU4: sc_hand[ 20/799].sh_func=ffffffc0003c2b60 rnd_wake                          .arg=0x0000000000000000  .sh_isr=0xffffffc062b300c0 [clk/4][clk block/4]
	CPU4: sc_hand[ 21/799].sh_func=ffffffc0001de420 ipintr                            .arg=0x0000000000000000  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 22/799].sh_func=ffffffc000210778 ip6intr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 23/799].sh_func=ffffffc0004b1eb0 route_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 24/799].sh_func=ffffffc00019cd80 cryptointr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 25/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb908  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 26/799].sh_func=ffffffc00019b618 cryptoret_softint                 .arg=0x0000000000000000  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 27/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fe4be418  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	CPU4: sc_hand[ 28/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bbba8  .sh_isr=0xffffffc062b30230 [net/4][net block/4]
	
	CPU5: sc_hand[  1/799].sh_func=ffffffc0004bf070 arpintr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[  2/799].sh_func=ffffffc0003d8c40 callout_softclock                 .arg=0x0000000000000000  .sh_isr=0xffffffc062b680c0 [clk/5][clk block/5]
	CPU5: sc_hand[  3/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062b68178 [ser/5][ser block/5]
	CPU5: sc_hand[  4/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[  5/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062b68008 [bio/5][bio block/5]
	CPU5: sc_hand[  6/799].sh_func=ffffffc000400c88 xc__highpri_intr                  .arg=0x0000000000000000  .sh_isr=0xffffffc062b680c0 [clk/5][clk block/5]
	CPU5: sc_hand[  7/799].sh_func=ffffffc0003d6548 timer_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062b680c0 [clk/5][clk block/5]
	CPU5: sc_hand[  8/799].sh_func=ffffffc0003f1328 logsoftintr                       .arg=0x0000000000000000  .sh_isr=0xffffffc062b680c0 [clk/5][clk block/5]
	CPU5: sc_hand[  9/799].sh_func=ffffffc000418000 ttysigintr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062b680c0 [clk/5][clk block/5]
	CPU5: sc_hand[ 10/799].sh_func=ffffffc000439838 biointr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062b68008 [bio/5][bio block/5]
	CPU5: sc_hand[ 11/799].sh_func=ffffffc0004a7998 pppoe_softintr_handler            .arg=0x0000000000000000  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 12/799].sh_func=ffffffc00003f5c8 plcomsoft                         .arg=0xffff0000ff2d6c68  .sh_isr=0xffffffc062b68178 [ser/5][ser block/5]
	CPU5: sc_hand[ 13/799].sh_func=ffffffc0004f2fe0 vioif_rx_softint                  .arg=0xffff0000fee49008  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 14/799].sh_func=ffffffc0004f2fb8 vioif_ctl_softint                 .arg=0xffff0000fee49008  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 15/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fee49248  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 16/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb748  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 17/799].sh_func=ffffffc00047ceb8 if_deferred_start_softint         .arg=0xffff0000ff2bb768  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 18/799].sh_func=ffffffc0001a4640 cprng_fast_intr                   .arg=0x0000000000000000  .sh_isr=0xffffffc062b68178 [ser/5][ser block/5]
	CPU5: sc_hand[ 19/799].sh_func=ffffffc0003c33b0 rnd_intr                          .arg=0x0000000000000000  .sh_isr=0xffffffc062b68178 [ser/5][ser block/5]
	CPU5: sc_hand[ 20/799].sh_func=ffffffc0003c2b60 rnd_wake                          .arg=0x0000000000000000  .sh_isr=0xffffffc062b680c0 [clk/5][clk block/5]
	CPU5: sc_hand[ 21/799].sh_func=ffffffc0001de420 ipintr                            .arg=0x0000000000000000  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 22/799].sh_func=ffffffc000210778 ip6intr                           .arg=0x0000000000000000  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 23/799].sh_func=ffffffc0004b1eb0 route_intr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 24/799].sh_func=ffffffc00019cd80 cryptointr                        .arg=0x0000000000000000  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 25/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bb908  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 26/799].sh_func=ffffffc00019b618 cryptoret_softint                 .arg=0x0000000000000000  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 27/799].sh_func=ffffffc0004813e8 if_link_state_change_si           .arg=0xffff0000fe4be418  .sh_isr=0xffffffc062b68230 [net/5][net block/5]
	CPU5: sc_hand[ 28/799].sh_func=ffffffc00047d760 if_percpuq_softint                .arg=0xffff0000ff2bbba8  .sh_isr=0xffffffc062b68230 [net/5][net block/5]

