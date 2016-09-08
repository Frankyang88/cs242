#include <stdio.h>
#include <stdlib.h>
#include "queue2.h"

struct q_item{
  double item;  
  q_item next;    
};

struct queue{
    q_item first;
    q_item last;
    int length;
};

queue queue_new(){
    queue q=malloc(sizeof (q));
    q->length=0; 
    q->first=malloc(sizeof(q->first));
    q->last=malloc(sizeof(q->last));
    (q->first)->next=NULL;
    (q->last)->next=NULL;
    return q;
}
void enqueue(queue q,double item){
    
    if(q->length==0){
     (q->first)->item=item;
     (q->first)->next=NULL;
      q->last=q->first;    
    }
    else {
        q_item tmp=malloc(sizeof(tmp));
        tmp->item=item;
        tmp->next=NULL;
        (q->last)->next=tmp;
        q->last=tmp;
    }
    
    q->length++;
    printf("queue length is :%d\n",q->length);
}
double dequeue(queue q){
    q_item tmp=(q->first);
    
    q->first=(q->first)->next; 
    
    q->length--;
    
    free(tmp);
    
    return (q->first)->item;
}
void queue_print(queue q){
    q_item tmp=q->first;
    while(tmp!=NULL){
        printf("%f\n",tmp->item);
        tmp=tmp->next;
    }
}
int queue_size(queue q){
    return q->length;
}
queue queue_free(queue q){
    q_item tmp=q->first;
    
    while(tmp!=NULL){
    q_item tmp1=tmp;    
    tmp=tmp->next;
    free(tmp1);   
    }
    free(q->first);
    free(q->last);
    free(q);
    
}