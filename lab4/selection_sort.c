#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ARRAY_MAX 30000

/* selection sort*/
// the loop outside start from the array index 0 to n-2, using i as the counter
// every cycle of i loop, picking the smallest data array[key] from the data on the right of array[i]
// then swap array[i] and array[key];
// As the data, which are on the left of i, are already sorted,the largest number is on the current position array[i];  
// So swap array[i] and array[key],make sure that the updated array[i] is always the smallest number following array[i-1];
// And because it starts from 0 to n-2, it is strictly ascending. 
// pick the smallest from the unsorted data set, add to the end of sorted data set;
// the original one must be all elements of the data, then it decrease by 1 every cycle.
void selection_sort(int *a,int n){
	int i,j;
	int key;

	
	for(i=0;i<n-1;i++){

	  //set up a[i] as the smallest key for  comparison with the rest of unsorted data
	  key=i;

	  //find the smallest from the rest of unsorted data
	  for(j=i+1;j<n;j++){
	     if( *(a+j) < *(a+key))
		key=j;
	  } 	

	  int tmp;

	  // swap a[i] with a[key]
	  tmp=*(a+key);
	  *(a+key)=*(a+i); 
	  *(a+i)=tmp;
	}	
}


int main(void){

clock_t start,end;      // timer for calculating efficiency
int my_array[ARRAY_MAX];//sorting data set
int i, count=0;         //array index counter   
int return_code;        //the return value of scan   

/*
read input data and initialize the data array */
while(count< ARRAY_MAX && 1== scanf("%d",&my_array[count])){
	count++;     					
}

start=clock();	               //record start time of sorting 
selection_sort(my_array,count);// selection sorting
end=clock(); 		       //record end time of sorting


// print the sorted array
for(i=0; i< count;i++){
	printf("%d\n",my_array[i]);
}

//calculate the time efficiency
fprintf(stderr,"%d %f \n",count,(end-start)/(double)CLOCKS_PER_SEC);

//exit, return value
return EXIT_SUCCESS;
}



