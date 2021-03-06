#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_MAX 100000



int merge_sort(int *a,int *w,int n){
	if(n<2)
	return 0;

	merge_sort(a,w,n/2);
	if(n%2==0)
	merge_sort(a+n/2,w,n/2);
	else merge_sort(a+n/2,w,n/2+1);

	int i;int j;int k;
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


int main(void){

clock_t start,end;      // timer 
int my_array[ARRAY_MAX];//data array
int my_sorted_data[ARRAY_MAX];
int i, count=0;         //array index counter
int return_code;        //return code for scanf 

// initialize the data array
while(count< ARRAY_MAX && 1== scanf("%d",&my_array[count])){
	count++;                                               
}

//record the start time of sorting
start=clock();
// merge sort data array
merge_sort(my_array,my_sorted_data,count);
//record the end time of sorting
end =clock();

//print sorted data
for(i=0; i< count;i++){
	printf("%d\n",my_array[i]);
}

//calculate the time efficiency
fprintf(stderr,"%d %f \n", count, (end-start)/(double)CLOCKS_PER_SEC);

//exit,return value
return EXIT_SUCCESS;
}


