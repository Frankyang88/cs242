#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

void *emalloc(size_t s) {
	void *result = malloc(s);
	if (NULL == result) {
	fprintf(stderr, "Memory allocation failed!\n");
	exit(EXIT_FAILURE);
	}
	return result;
}
void *erealloc(void *p, size_t s) {
	p = realloc(p,s);
	if (NULL == p) {
	fprintf(stderr, "Memory allocation failed!\n");
	exit(EXIT_FAILURE);
	}
	return p;
}


void insertion_sort(int *a,int n){
 	int i,j;
	int key;
	

	for(i=1;i<n;i++){
	
	   if(i == n/2){	 
	  	for(j=0;j<n;j++)		
		fprintf(stderr,"%d\n",a[j]);
		}
	  
	  key=*(a+i);
  
	  for(j=i-1;j>=0 && key< *(a+j);j--){
	    *(a+j+1)=*(a+j);	
	  }

	  *(a+j+1)=key;
	}	
}



struct flexarrayrec{
int capacity;
int itemcount;
int *items;
};

flexarray flexarray_new() {
flexarray result = emalloc(sizeof *result);
result->capacity = 2;
result->itemcount = 0;
result->items = emalloc(result->capacity * sizeof result->items[0]);
return result;
}

void flexarray_append(flexarray f, int num) {
if (f->itemcount == f->capacity) {
  f->items=erealloc(f->items,2*f->capacity*sizeof(int));
  f->capacity *= 2;
}
  f->items[f->itemcount]=num;
  f->itemcount++;

}


void flexarray_print(flexarray f) {
	int i;
	for (i = 0; i < f->itemcount; i++) {
		printf("%d\n", f->items[i]);
	}
}


void flexarray_sort(flexarray f) {
 
  insertion_sort(f->items,f->itemcount);
  
}

void flexarray_free(flexarray f) {
 free(f->items);
 free(f);
}




