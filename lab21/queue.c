#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"

/* * queue structure, array with fix size
 * @param : item, data array
 * @param: head,the first item in the queue
 * @param: capacity,the maximum size of queue
 * @param: num_items,the maximum size of items
 * a pointer pointer to the head and  a counter count its length*/
struct queuerec{
    int *item;
    int head;
    int capacity;
    int num_items;
};

/*create a queue with size
 *@param : size ,the maximum size of queue */
queue queue_new(int size){
    queue q=malloc(sizeof (*q));
    if(size >0)
    q->capacity=size;
    else printf("Exception! queue size must be bigger than 0"); 
    q->head=0;
    q->num_items=0;
    q->item=malloc(q->capacity*sizeof(int));
    return q;
}

/* enqueue:
 * @param: q: the queue that insert item into 
 * @param: item, the items that insert into queue q 
 * */
void enqueue(queue q,int item){
    if(q->num_items<q->capacity)
    q->item[(q->head+q->num_items)%(q->capacity)]=item;
    else {printf("queue full!\n");
            return ;
    }
    q->num_items++;
}
/*dequeue:
 * @param : q the queue of which the first item should be delete
 * delete the first item in the queue q
 *
 *
 * */
int dequeue(queue q){
    int j = q->head;
    q->head=(q->head+1)% (q->capacity);
    q->num_items --;
    return q->item[j];
}
/* queue print
 * @param: q,the q that prints all its items from head to end
 * 
 * */
void queue_print(queue q){
    int i=0;
    for(i=0;i<q->num_items;i++)
    printf("%d\n",q->item[(q->head+i)%(q->capacity)] );
}
/* queue size:
 * @param: q .print the size of queue q 
 *
 * */
int queue_size(queue q){
    return q->num_items;
}
/* queue free:
 *
 * free the memory allocation of queue q 
 *
 * */
void queue_free(queue q){
    free(q->item);
    free(q);
}
