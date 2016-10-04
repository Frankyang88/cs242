#include <stdio.h> 
#include <stdlib.h> 
#include "mylib.h"
#include <assert.h>
#include <ctype.h>
/*memory allocation with size s*/
void *emalloc(size_t s) {
	void *result = malloc(s);
	if (NULL == result) {
	fprintf(stderr, "Memory allocation failed!\n");
	exit(EXIT_FAILURE);
	}
	return result;
}
/*memory reallocation for pointer p with size s */
void *erealloc(void *p, size_t s) {
	p = realloc(p,s);
	if (NULL == p) {
	fprintf(stderr, "Memory allocation failed!\n");
	exit(EXIT_FAILURE);
	}
	return p;
}
int getword(char *s, int limit, FILE *stream){
	int c;
	char *w=s;
	assert(limit >0 && s!=NULL && stream !=NULL);

	while(!isalnum( c = getc(stream)) && EOF != c)
	;
	if(EOF == c){
	return EOF;
	}
	else if(--limit > 0){
	*w++=tolower(c);
	}
	while(--limit >0){
		if(isalnum(c = getc(stream))){
		*w++=tolower(c);	
		}
		else if( '\'' == c){
			limit++;
		}
		else break;
	}
	*w='\0';
	return w-s;
}

