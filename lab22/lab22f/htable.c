#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include "htable.h"
#include <string.h>

struct htablerec{
  char **keys;
  int capacity; 
}; 

static unsigned int htable_word_to_int(char *word) {
  unsigned int result = 0;

  while (*word != '\0') {
     result = (*word++ + 31 * result);
  }
  return result;
}

static unsigned int htable_hash(htable h, unsigned int i_key) {
  return i_key % h->capacity;
}

htable htable_new(int size){
  int i;
  htable h=emalloc(sizeof(*h));
  h->capacity = size;
  h->keys = emalloc(size* sizeof(h->keys[0]));
 
  for(i=0;i<h->capacity;i++){
    h->keys[i]=NULL;
  }
  return h;
}
void htable_insert(htable h, char *str){
  unsigned int k = htable_word_to_int(str);
  unsigned int key = htable_hash(h,k);
  int x = 0;
  
  if( h->keys[key] == NULL){
    h->keys[key] = emalloc(sizeof(str));
    strcpy(h->keys[key],str);
  }
  else{
    if(strcmp(h->keys[key],str)==0){
      return ; 
    }
    else {

      while(1){
	key++;
	key %= h->capacity;
	
	if(h->keys[key] == NULL){
	  h->keys[key] = emalloc(sizeof(str));
	  strcpy(h->keys[key],str);
	  return ;
	}
	if(h->keys[key]!=NULL){
	  if(strcmp(h->keys[key],str)==0){
	    return ;
	  }
	}
	x++;
	if(x> h->capacity)
	  break;
      }
    }
    
   
  }

}

void htable_free(htable h){
  int i;
  for(i=0;i<h->capacity;i++){
    if(h->keys[i]!=NULL){
      free(h->keys[i]);
    }
  }
  free(h->keys);
  free(h);
  
}
void htable_print(htable h,FILE *stream){
  int i;
  for( i=0;i<h->capacity;i++){

    fprintf(stream,"%2d %s\n",i,h->keys[i]==NULL?"":h->keys[i]);
  }

}
