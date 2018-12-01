#ifndef _KSYMS_SUBR_H_
#define _KSYMS_SUBR_H_

int ksyms_load(void);
void ksyms_destroy(void);
void ksyms_dump(void);
const char *ksyms_lookup(unsigned long);


#endif /* _KSYMS_SUBR_H_ */
