#include "queue.h"
#include "main.h"


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

int enqueue_node(tQueue *queue, char *name, char *PhoneNumber, int PhoneType, enum OperatorType op, char *area)
{
    tQueueNode *newNode;
    newNode = (tQueueNode *) malloc (sizeof(tQueueNode));
    if (!newNode)
    {
        return 0;
    }
    strcpy(newNode->name, name);
    if (PhoneType == HOME)
    {
        newNode->phoneType = HOME;
        newNode->home.area[0] = area[0];
        newNode->home.area[1] = area[1];
        strcpy(newNode->home.number, PhoneNumber);
    }
    else if (PhoneType == CELLUAR)
    {
        newNode->phoneType = CELLUAR;
        newNode->celluar.op = op;
        strcpy(newNode->celluar.number, PhoneNumber);
    }
    else
    {
        return 0;
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    if (queue->count == 0)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        newNode->prev = queue->rear;
        queue->rear = newNode;
    }
    queue->count++;
    return 1;
}


void print_queue (tQueue *queue)
{
    int i;
    tQueueNode *target = queue->front;
    printf("\n");
    printf("Phone Book\n----------------\n");
    for (i = 0; i < queue->count; i++)
    {
        printf("%s \n", target->name);
        if(target->phoneType == HOME)
        {
            printf("Home\n");
            printf("Area:%c%c\n", target->home.area[0], target->home.area[1]);
            printf("Phone_Number:%s\n", target->home.number);
        }
        else
        {
            if(target->celluar.op == CHT)
            {
                printf("Celluar\nOperator: CHT\n");
            }
            else if(target->celluar.op == FET)
            {
                printf("Celluar\nOperator: FET\n");
            }
            else if(target->celluar.op == TWN)
            {
                printf("Celluar\nOperator: TWN\n");
            }
            printf("Phone_Number:%s\n", target->celluar.number);
        }
        printf("----------------\n");
        target = target->next;
    }
    printf("\n\n");
}