#ifndef __QUEUE__
#define __QUEUE__
#include "main.h"
typedef struct queue_node {
    char name[10];
    int phoneType; // 标记是 HOME 还是 CELLUAR
    union {
        struct {
            char area[2];
            char number[100];
        } home;
        struct {
            enum OperatorType op;
            char number[100];
        } celluar;
    };
    struct queue_node *next;
    struct queue_node *prev;
} tQueueNode;
 

typedef struct {
    tQueueNode *front;
    tQueueNode *rear;
    int count;
}tQueue;


tQueue* createQueue(void);

int enqueue_node(tQueue *queue, char *name, char *PhoneNumber, int PhoneType, enum OperatorType op, char *area);
void print_queue(tQueue *queue);

#endif