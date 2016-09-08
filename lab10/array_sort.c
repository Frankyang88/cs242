#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

void array_sort(int *a,int n){
 	int i,j;
	int key;

	for(i=1;i<n;i++){

	  
	  key=*(a+i);
  
	  for(j=i-1;j>=0 && key< *(a+j);j--){
	    *(a+j+1)=*(a+j);	
	  }

	  *(a+j+1)=key;
	}	
}

static void array_print(int *a, int n) {
int i;
for (i = 0; i < n; i++) {
printf("%d\n", a[i]);
}
}
int main(void) {
int capacity = 2;
int itemcount = 0;
int item;
int *my_array = emalloc(capacity * sizeof my_array[0]);

while (1 == scanf("%d", &item) && itemcount<=10) {
if (itemcount == capacity) {
capacity += capacity;
my_array = realloc(my_array, capacity * sizeof my_array[0]);
}
my_array[itemcount++] = item;
}

array_sort(my_array,itemcount);
array_print(my_array, itemcount);

free(my_array);

return EXIT_SUCCESS;
}
