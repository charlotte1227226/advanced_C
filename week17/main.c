#include "main.h"
#include "queue.h"
int main(){
    tQueue *queue;
    queue = createQueue();
    tQueueNode *target_node;
    char name[10];
    char PhoneNumber[100];
    int PhoneType;
    int ret;
    enum OperatorType op;
    while(1){
        printf("Enter your name: ");
        scanf("%s", name);
        printf("Enter your phone type (1: Home, 2: Celluar): ");
        scanf("%d", &PhoneType);
        if (PhoneType == HOME){
            printf("Enter your phone number: ");
            scanf("%s", PhoneNumber);
            char area[2];
            area[0] = PhoneNumber[0];
            area[1] = PhoneNumber[1];
            ret = enqueue_node(queue, name, PhoneNumber, PhoneType, op, area);
        }
        else if (PhoneType == CELLUAR){
            printf("Enter your operator type (0: CHT, 1: FET, 2: TWN): ");
            scanf("%d", &op);
            printf("Enter your phone number: ");
            scanf("%s", PhoneNumber);
            ret = enqueue_node(queue, name, PhoneNumber, PhoneType, op, NULL);
        }
        else{
            printf("Error: PhoneType\n");
        }
        print_queue(queue);
    }
    return 0;
}
