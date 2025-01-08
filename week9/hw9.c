#include<stdio.h>
#include<stdlib.h>
typedef struct num_storage{
    int number;
    struct num_storage *next;
    struct num_storage *prev;
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
void delete_last(tNumStorHead *list);
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
    printf("\n");
    printf("list->counts=%d\n", list->counts);
    printf("From head --> ");
    while(node_ptr != NULL){
        printf("%d " , node_ptr->number);
        node_ptr = node_ptr->next;
    }
    node_ptr = list->tail;
    printf("\nFrom tail --> ");
    while(node_ptr != NULL){
        printf("%d " , node_ptr->number);
        node_ptr = node_ptr->prev;
    }
    printf("\n\n");
}
void get_input(tNumStorHead *list){
    int input = 0, result;
    while(input != -1){
        printf("Input a number(-1 yo exit, -2 to delete last):");
        scanf("%d" , &input);
        if(input == -2){
            delete_last(list);
        }
        else if(input != -1){
            sort_list(list, input);
        }
    }
}
void sort_list(tNumStorHead *list, int input) {
    tNumStorage *input_temp = (tNumStorage *)malloc(sizeof(tNumStorage));
    input_temp->number = input;
    input_temp->next = NULL;
    input_temp->prev = NULL;

    if (list->counts == 0) {
        list->head = input_temp;
        list->tail = input_temp;
    } else {
        tNumStorage *current_temp = list->head;
        tNumStorage *last_temp = NULL;
        if (input_temp->number < current_temp->number) {
            input_temp->next = current_temp;
            current_temp->prev = input_temp;
            list->head = input_temp;
        } else {
            while (current_temp != NULL && input_temp->number >= current_temp->number) {
                last_temp = current_temp;
                current_temp = current_temp->next;
            }
            if (last_temp != NULL) {
                last_temp->next = input_temp;
                input_temp->prev = last_temp;
            }
            if (current_temp != NULL) {
                current_temp->prev = input_temp;
                input_temp->next = current_temp;
            } else {
                list->tail = input_temp;
            }
        }
    }
    list->counts++;
    print_list(list);
}

void delete_last(tNumStorHead *list) {
    if (list->counts == 0) {
        printf("List is already empty.\n");
        return;
    }
    tNumStorage *temp = list->tail;
    if (list->counts == 1) {
        free(temp);
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = temp->prev;
        list->tail->next = NULL;
        free(temp);
    }
    list->counts--;
    print_list(list);
}
