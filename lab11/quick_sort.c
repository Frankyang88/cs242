#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

int quick_sort(int *a,int n){
 	int i,j;
	int key;
        if(n<2)
	 return 0;      

	key=*a;
	i=0;
	j=n-1;
	
	printf("pivet is :%d\n",key);
	
	for(i=0;i<n;i++)
        printf("%d ",*(a+i));
	printf("\n");
	i=0;

	while(1){
	 
	while(a[i]<key && i<n) i++;
	while(a[j]>key && j>0) j--;	

	if(i<j){
	int tmp;
	tmp=a[j];
	a[j]=a[i];
	a[i]=tmp;
	}
	else break;	
	}
	
	quick_sort(a,i);
        quick_sort(a+i+1,n-i-1); 

	return 0;
}

static void array_print(int *a, int n) {
int i;
for (i = 0; i < n; i++) {
printf("%d\n", a[i]);
}
}
int main(void) {
int capacity = 100;
int itemcount = 0;
int item;
int *my_array =emalloc(capacity * sizeof my_array[0]);

while (1 == scanf("%d", &item) && itemcount<=10) {
 
	my_array[itemcount]=item;
	itemcount++;
}



quick_sort(my_array,itemcount);
array_print(my_array, itemcount);

free(my_array);

return EXIT_SUCCESS;
}
