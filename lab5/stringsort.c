#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define STRING_LEN 80
#define ARRAY_LEN 100

void *emalloc(size_t s){
	void *result =malloc(s);
	if(NULL == result){
	fprintf(stderr,"Memory allocation failed!\n");
	exit(EXIT_FAILURE);
}
	return result;	
}
 
void insertion_sort(char* a[],int n){
 	int i,j;
	char *key;

	for(i=1;i<n;i++){
	
	  //keep the current index i as a key
	  key = a[i];
	  
	  //move the data on the left of a[i] to one step right if it is bigger than the key
	  //j start from i-1 since a[i] have been saved in key 
	  //at the end of this loop, there will be a vacancy,which hold its index as (j+1);  
	  for(j=i-1;j>=0 && strcmp(key,a[j])<0;j--){
	    *(a+j+1)=*(a+j);	
	  }

	  //move the key into the vacancy
	  *(a+j+1)=(char *) key;
	}	

}

int main(void){
	char word[STRING_LEN];
	char *wordlist[ARRAY_LEN];
	int num_words;
	double average;
	int i;
	num_words=0;

	while(num_words < ARRAY_LEN && 1== scanf("%79s",word)){
	wordlist[num_words]= emalloc((strlen(word)+1)*sizeof(wordlist[0][0]));
	strcpy(wordlist[num_words],word);
	num_words++;
	}
	printf("reading success\n");
        insertion_sort(wordlist,num_words); 

	average=0;
	for (i=0; i< num_words; i++){
	average+= strlen(wordlist[i]);
	printf(" %s\n",wordlist[i]);
	}

	average=average / num_words;
	for(i=0;i< num_words;i++)
	free(wordlist[i]);

	return EXIT_SUCCESS;
}
