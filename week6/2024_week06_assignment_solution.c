#include<stdio.h>
#include<stdlib.h>
typedef struct num_storage{
    int number;
    struct num_storage *next;
}tNumStorage;

typedef struct num_stor_head{
    int counts;
    struct num_storage *head;
    struct num_storage *tail;
}tNumStorHead;
void initial_list(tNumStorHead *list);
void get_input(tNumStorHead *list);
void print_list(tNumStorHead *list);
void sort_list(tNumStorHead *list, int input);

int main(){
    int i;
    tNumStorHead *list;
    list = (tNumStorHead *)malloc(sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
    return 0;
}
void initial_list(tNumStorHead *list){
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;   
}
void print_list(tNumStorHead *list){
    tNumStorage *node_ptr = list->head;
    printf("the sorted list: ");
    while(node_ptr != NULL){
        printf("%d " , node_ptr->number);
        node_ptr = node_ptr->next;
    }
    printf("\n\n");
}
void get_input(tNumStorHead *list){
    int a = 0;
    while(a != -1){
        printf("Input a number:");
        scanf("%d" , &a);
        if(a != -1){
            sort_list(list,a);
        }
    }
}
void sort_list(tNumStorHead *list, int input){
    tNumStorage *input_temp = (tNumStorage *)malloc(sizeof(tNumStorage));
    input_temp->number = input;
    input_temp->next = NULL;
    if(list->counts==0){
        list->head = input_temp;
        list->tail = input_temp;
    }
    else{
        tNumStorage *current_temp, *last_temp;
        current_temp = list->head;
        last_temp = NULL;
        if (input_temp->number < current_temp->number) {
            input_temp->next = current_temp;
            list->head = input_temp;
        }
        else {
            while (current_temp != NULL){
                if(input_temp->number >= current_temp->number){
                last_temp = current_temp;
                current_temp = current_temp->next;
                }
                else if(input_temp->number < current_temp->number){
                input_temp->next = current_temp;
                last_temp->next = input_temp;
                break;
                }
            }
            if(current_temp == NULL){
                last_temp->next = input_temp;
                list->tail = input_temp;
            }
            else{
                list->tail = current_temp;
            }
        }
    }
    list->counts++;
    printf("list->counts : %d\n", list->counts);
    print_list(list);
}