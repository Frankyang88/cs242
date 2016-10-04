#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <string.h>
#include "mylib.h"

struct bstnode{
  char *key;
  bst left;
  bst right;    
};

bst    bst_free(bst b){
  if(b!=NULL){
    if(b->left !=NULL)
      bst_free(b->left);

    if(b->right !=NULL)
      bst_free(b->right);
    free(b->key);
    free(b);    
  }

  return b;
}
void  bst_inorder(bst b, void f(char *str)){
  if(b==NULL ) return ;
  
  bst_inorder(b->left,f);
  f(b->key);
  bst_inorder(b->right,f);
}

bst bst_insert(bst b, char *str){

  if (b == NULL){
      b=bst_new();     
      b->key = emalloc((strlen(str)+1) * sizeof(char) );
      strcpy(b->key, str);
      return b;
   }
  if(b->key != NULL){
   if (strcmp(str, b->key)==0){
      return NULL;
   }
   else if (strcmp(str, b->key)<0){
      b->left = bst_insert(b->left, str);
   }
   else if (strcmp(str, b->key)>0){
      b->right = bst_insert(b->right, str);
   }
  }else {
      b->key = emalloc((strlen(str)+1) * sizeof(char) );
      strcpy(b->key, str);
  }
   return b;
  
}
bst bst_new(){
    bst b = emalloc(sizeof(*b));
    b->left =NULL;
    b->right = NULL;
    b->key = NULL;

    return b;
}

void bst_preorder(bst b, void f(char *str)){
  if(b == NULL ) return ;
  f(b->key);
  bst_preorder(b->left,f);
  bst_preorder(b->right,f);
  
}
int bst_search(bst b, char *str){
 
 
   if (b == NULL){
      return 0;
   }
   else if (strcmp(str, b->key)==0){
      return 1;
   }
   else if (strcmp(str, b->key)<0){
      return bst_search(b->left, str);
   }
   else if (strcmp(str, b->key)>0){
      return bst_search(b->right, str);
   }
   return 0;
}
