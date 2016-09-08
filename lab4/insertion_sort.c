#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_MAX 30000
// insertion sort
// the loop outside use i as an index, it begin from 1 to n-1
// As it start from 1 to n-1; The data on the left of i are already sorted. 
// the selected data array[i] is inserted into the sorted data set(the data set whose are on the left of array[i]). 
// Thus, through comparison, it knows that the array[i] should be inserted into the vacancy.

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


int main(void){

clock_t start,end;      // timer 
int my_array[ARRAY_MAX];//data array
int i, count=0;         //array index counter
int return_code;        //return code for scanf 

// initialize the data array
while(count< ARRAY_MAX && 1== scanf("%d",&my_array[count])){
	count++;                                               
}

//record the start time of sorting
start=clock();
// insertion sort data array
insertion_sort(my_array,count);
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



