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
    tQueueNode *queue_node;
    void *newptr = NULL;
    int mem_location;
    our_malloc(data_type, (void *)&newptr, &mem_location);
    if (newptr == NULL)
    {
        printf("    Enqueue False!!! \n");
        return 0;
    }
    if(data_type == TYPE_SMALL)
    {
        tQueueSmall *small = (tQueueSmall *)newptr;
        small->id = id;
        small->location = mem_location;
        small->score = score;
        //printf("    small id: %d, location: %d, score: %d\n", small->id, small->location, small->score);
    }
    else if(data_type == TYPE_LARGE)
    {
        tQueueLarge *large = (tQueueLarge *)newptr;
        large->id = id;
        large->location = mem_location;
        large->score = score;
        //printf("    large id: %d, location: %d, score: %d\n", large->id, large->location, large->score);
    }
    queue_node = (tQueueNode *)malloc(sizeof(tQueueNode));
    if(queue->count == 0)
    {
        queue_node->data_type = data_type;
        printf("data_type: %d\n", queue_node->data_type);
        queue_node->content = newptr;
        queue_node->next = NULL;
        queue_node->prev = NULL;
        queue->front = queue_node;
        queue->rear = queue_node;
    }
    else
    {
        queue_node->data_type = data_type;
        printf("data_type: %d\n", queue_node->data_type);
        queue_node->content = newptr;
        queue_node->next = NULL;
        queue_node->prev = queue->rear;
        queue->rear->next = queue_node;
        queue->rear = queue_node;
    }
    //printf("    Enqueue Success!!! \n");
    //printf("    id: %d, location: %d, score: %d\n", id, mem_location, score);
    queue->count++;
    return 1;
}

void dequeue_node(tQueue *queue, tQueueNode *target, int data_type)
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
    if(data_type == TYPE_SMALL)
    {
        target->content = (tQueueSmall *)target->content;
        //printf("data_type: %d\n", data_type);
        our_free(data_type, ((tQueueSmall *)target->content)->location);
    }
    else if(data_type == TYPE_LARGE)
    {
        target->content = (tQueueLarge *)target->content;
        //printf("data_type: %d\n", data_type);
        our_free(data_type, ((tQueueLarge *)target->content)->location);
    }
}

tQueueNode *find_target_node(tQueue *queue, int id, int data_type)
{
    int i;
    tQueueNode *target = queue->front;
    printf("data_type: %d\n", data_type);
    printf("id: %d\n", id);
    for (i = 0; i < queue->count; i++)
    {
        if(target->data_type == data_type && data_type == TYPE_SMALL)
        {
            if(((tQueueSmall *)target->content)->id == id)
            {
                printf("    Find Small!!! \n");
                return target;
            }
        }
        else if(target->data_type == TYPE_LARGE && data_type == TYPE_LARGE)
        {
            if(((tQueueLarge *)target->content)->id == id)
            {
                printf("    Find Large!!! \n");
                return target;
            }
        }
        target = target->next;
    }
    return NULL;
}


void print_queue (tQueue *queue)
{
    int i;
    tQueueNode *target = queue->front;
    //printf("data_type: %d\n", target->data_type);
    //printf("%d %d(%d,%d) ", ((tQueueSmall *)target->content)->id, ((tQueueSmall *)target->content)->score, target->data_type, ((tQueueSmall *)target->content)->location); 
    printf("      type mixed queue: ");    
    for (i = 0; i < queue->count; i++)
    {
        if(target->data_type == TYPE_SMALL)
        {
            printf("%d %d(%d,%d) ,", ((tQueueSmall *)target->content)->id, ((tQueueSmall *)target->content)->score, target->data_type, ((tQueueSmall *)target->content)->location); 
        }
        else if(target->data_type == TYPE_LARGE)
        {
            printf("%d %d(%d,%d) ,", ((tQueueLarge *)target->content)->id, ((tQueueLarge *)target->content)->score, target->data_type, ((tQueueLarge *)target->content)->location);
        }
        target = target->next;
    }
    printf("\n");
}