#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
struct queue{
    double *item;
    int head;
    int capacity;
    int num_items;
};

queue queue_new(){
    queue q=malloc(sizeof (q));
    q->capacity=5; 
    q->head=0;
    q->num_items=0;
    q->item=malloc(q->capacity*sizeof(double));
    return q;
}
void enqueue(queue q,double item){
    if(q->num_items<q->capacity)
    q->item[(q->head+q->num_items)%(q->capacity)]=item;
    else {printf("queue full!\n");
            return ;
    }
    q->num_items++;
}
double dequeue(queue q){
    q->head=(q->head+1)% (q->capacity);
    q->num_items --;
    return q->item[q->head];
}
void queue_print(queue q){
    int i=0;
    for(i=0;i<q->num_items;i++)
    printf("%f\n",q->item[(q->head+i)%(q->capacity)] );
}
int queue_size(queue q){
    return q->num_items;
}
queue queue_free(queue q){
    free(q->item);
    free(q);
}