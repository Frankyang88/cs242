#ifndef MYLIB_H_
#define MYLIB_H_
#include <stddef.h>
/*memory allocation*/
extern void *emalloc(size_t);
/*memory re allocation*/
extern void *erealloc(void *, size_t);
extern int getword(char *s, int limit, FILE *stream);


 
#endif
