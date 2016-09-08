#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

int merge_sort(int *a,int *w,int n){
        int i,j,k;
	if(n<2)
	return 0;

	if(n%2 ==0){
	  merge_sort(a,w,n/2);
	  merge_sort(a+n/2,w,n/2);	
	}
	else {
	merge_sort(a,w,(n-1)/2);
	merge_sort(a+(n-1)/2,w,(n+1)/2);
	}
	
	i=0;j=n/2;k=0;
	while(i<n/2 && j< n){

		if(a[i]<a[j]){
		 *(w+k)=a[i];
			i++;
		}
		else {
			*(w+k)=a[j];
			j++;
			}
		k++;	
	}
	while(i<n/2){
		 *(w+k)=a[i];
		i++;
		k++;}	 
	while(j<n){
		*(w+k)=a[j];
		j++;
		k++;
		}
	for(i=0;i<n;i++){
		*(a+i)=*(w+i);
	}
}



struct flexarray{
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
  f=erealloc(f,2*(f->capacity)*sizeof(f->items[0]));
}
  f->items[f->itemcount]=num;
  f->itemcount++;
/* insert the item in the last free space */
}
void flexarray_print(flexarray f) {
int i;
for (i = 0; i < f->itemcount; i++) {
printf("%d\n", f->items[i]);
}
}
void flexarray_sort(flexarray f) {
  int *a;
  
  int n=f->itemcount;
  int w[n]; 
  printf("%d,%d\n",f->items[0],n);
  
  a=&(f->items[0]);
 
 
  merge_sort(a,w,n);
  
}

void flexarray_free(flexarray f) {
 free(f);
}




