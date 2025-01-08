#include "queue.h"
#include "space.h"


tQueue* createQueue(void){    
    tQueue *queue;
    queue=(tQueue *) malloc (sizeof(tQueue));

    if (queue)
    {
        queue->front=NULL;
        queue->rear=NULL;  
        queue->count=0;
    }

    return queue;
}

int enqueue_node(tQueue *queue, int id, int score, int data_type)
{
    tQueueNode *newptr = NULL;
    int mem_location;

    our_malloc(data_type, (void *)&newptr, &mem_location);
    if (newptr == NULL)
    {
        printf("    Enqueue False!!! \n");
        return 0;
    }
    newptr->id = id;
    newptr->score = score;
    newptr->data_type = data_type;
    newptr->location = mem_location;
    if (queue->count == 0)
    {
        queue->front = newptr;
        queue->rear = newptr;
        newptr->next = NULL;
        newptr->prev = NULL;
    }
    else
    {
        newptr->next = NULL;
        newptr->prev = queue->rear;
        queue->rear->next = newptr;
        queue->rear = newptr;
    }
    queue->count++;
    return 1;
}

void dequeue_node(tQueue *queue, tQueueNode *target)
{
    if (queue->count == 0)
    {
        printf("    Dequeue False!!! \n");
        return;
    }
    if (queue->count == 1)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        if (target == queue->front)
        {
            queue->front = target->next;
            queue->front->prev = NULL;
        }
        else if (target == queue->rear)
        {
            queue->rear = target->prev;
            queue->rear->next = NULL;
        }
        else
        {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
    }
    queue->count--;
    our_free(target->location, target->data_type);
}

tQueueNode *find_target_node(tQueue *queue, int id)
{
    int i;
    tQueueNode *target = queue->front;
    for (i = 0; i < queue->count; i++)
    {
        if (target->id == id)
        {
            return target;
        }
        target = target->next;
    }
    return NULL;
}


void print_queue (tQueue *queue)
{
    int i;
    tQueueNode *target = queue->front;
    int count = NUM_BYTE_BUF;
    printf("      queue content: ");    
    for (i = 0; i < queue->count; i++)
    {
        count = count - target->data_type;
        printf ("%d(%d, %d) ", target->id, target->location, target->data_type);
        target = target->next;
    }
    printf("\n\n");
    printf("Remaining memory space %d", count);
}