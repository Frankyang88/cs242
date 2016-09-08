#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_MAX 2000000


void insertion_sort(int *a,int n){
 	int i,j;
	int key;

	for(i=1;i<n;i++){

	  //keep the current index i as a key
	  key=*(a+i);

	  //move the data on the left of a[i] to one step right if it is bigger than the key
	  //j start from i-1 since a[i] have been saved in key 
	  //at the end of this loop, there will be a vacancy,which hold its index as (j+1);  
	  for(j=i-1;j>=0 && key< *(a+j);j--){
	    *(a+j+1)=*(a+j);	
	  }

	  //move the key into the vacancy
	  *(a+j+1)=key;
	}	
}



int merge_sort(int *a,int *w,int n){
	if(n<43){
	insertion_sort(a,n);		
	}
	else {
	merge_sort(a,w,n/2);
	if(n%2==0)
	merge_sort(a+n/2,w,n/2);
	else merge_sort(a+n/2,w,n/2+1);
	}
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
int *my_array=malloc(ARRAY_MAX*sizeof(int));//data array
int *my_sorted_data=malloc(ARRAY_MAX*sizeof(int));

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

/*print sorted data
for(i=0; i< count;i++){
	printf("%d\n",my_array[i]);
}
*/

//calculate the time efficiency
fprintf(stderr,"%d %f \n", count, (end-start)/(double)CLOCKS_PER_SEC);
free(my_array);
free(my_sorted_data);
//exit,return value
return EXIT_SUCCESS;
}



