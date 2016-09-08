#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    queue q=queue_new();
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,1);
    if(queue_size(q)==5)
    queue_print(q);
    dequeue(q);
    dequeue(q);
    queue_print(q);
    enqueue(q,7);
    queue_print(q);
    queue_free(q);

    return 0;
}

