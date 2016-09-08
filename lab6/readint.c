#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 9
#define ARRAY_MAX  7
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
//test:1 1 3 4 4 6 7 8 9
int binary_search(int a[],int n,int m){
	
	int i= n/2;

	if(n<=1 && a[0]!=m){
	printf("search failed,-\n");	
	}else {
	if(a[i]>m)
	   return binary_search(a,i,m);
	else if(a[i]<m)
            return binary_search(a+i,n-i,m);		
	else printf("find %d,+\n",m);
	}
	return 0;
}


int main(int argc, char **argv) {
FILE *infile;
int my_array[ARRAY_SIZE];
int my_array1[ARRAY_MAX];
int num_items;
int count;
int i;

if (NULL == (infile = fopen(argv[1], "r"))) {
fprintf(stderr, "%s: can’t find file %s\n", argv[0], argv[1]);
return EXIT_FAILURE;
}
num_items = 0;
while (num_items < ARRAY_SIZE &&
1 == fscanf(infile, "%d", &my_array[num_items])) {
num_items++;
}
fclose(infile);

insertion_sort(my_array,num_items);

/*
read input data and initialize the data array */
while(count< ARRAY_MAX && 1== scanf("%d",&my_array1[count])){
	count++;     					
}
for(i=0;i<count;i++){
binary_search(my_array,num_items,my_array1[i]);
}


return EXIT_SUCCESS;
}
