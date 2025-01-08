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
void add_num(tNumStorHead *list);
void delete_num(tNumStorHead *list);
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
    printf("counts: %d\n", list->counts);
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
    int a = 0, input = 0;
    while(a != -1){
        printf("1. Add a number or 2. Delete a number:");
        scanf("%d" , &input);
        if(input == 1){
            add_num(list);
        }
        else if(input == 2){
            delete_num(list);
        }
        else{
            printf("No such choose !\n");
        }
    }
}
void add_num(tNumStorHead *list){
    int input = 0, location = 0;
    tNumStorage *input_temp = (tNumStorage *)malloc(sizeof(tNumStorage));
    input_temp->number = input;
    input_temp->next = NULL;
    input_temp->prev = NULL;

    printf("add a number:");
    scanf("%d" , &input);
    input_temp->number = input;
    if(list->counts == 0){
        list->counts++;
        list->head = input_temp;
        list->tail = input_temp;
        print_list(list);
    }
    else{
        int before_after = 0;
        tNumStorage *target_temp = list->head;
        printf("Specify a target location:");
        scanf("%d", &location);
        while(location < 1 || location > list->counts){
            printf("No such location !\n");
            printf("Specify a target location:");
            scanf("%d", &location);
        }
        if(location == 1 && list->counts == 1){
            printf("1. Before or 2. After the location %d:", location);
            scanf("%d", &before_after);
            if(before_after == 1){
                input_temp->prev = NULL;
                input_temp->next = list->head;
                list->head->prev = input_temp;
                list->head = input_temp;
                list->counts++;
                print_list(list);
            }
            else if(before_after == 2){
                input_temp->prev = list->head;
                input_temp->next = NULL;
                list->head->next = input_temp;
                list->tail = input_temp;
                list->counts++;
                print_list(list);
            }
            else{
                printf("No such choose !\n");
            }
        }
        else if(location == 1){
            printf("1. Before or 2. After the location %d:", location);
            scanf("%d", &before_after);
            if(before_after == 1){
                input_temp->prev = NULL;
                input_temp->next = list->head;
                list->head->prev = input_temp;
                list->head = input_temp;
                list->counts++;
                print_list(list);
            }
            else if(before_after == 2){
                input_temp->prev = list->head;
                input_temp->next = list->head->next;
                list->head->next->prev = input_temp;
                list->head->next = input_temp;
                list->counts++;
                print_list(list);
            }
            else{
                printf("No such choose !\n");
            }
        }
        else if(location != list->counts){
            for(int i = 1; i < location; i++){
                target_temp = target_temp->next;
            }
            printf("1. Before or 2. After the location %d:", location);
            scanf("%d", &before_after);
            if(before_after == 1){
                input_temp->prev = target_temp->prev;
                input_temp->next = target_temp;
                target_temp->prev->next = input_temp;
                target_temp->prev = input_temp;
                list->counts++;
                print_list(list);
            }
            else if(before_after == 2){
                input_temp->prev = target_temp;
                input_temp->next = target_temp->next;
                target_temp->next->prev = input_temp;
                target_temp->next = input_temp;
                list->counts++;
                print_list(list);
            }
            else{
                printf("No such choose !\n");
            }
        }
        else{
            printf("1. Before or 2. After the location %d:", location);
            scanf("%d", &before_after);
            if(before_after == 1){
                input_temp->prev = list->tail->prev;
                input_temp->next = list->tail;
                list->tail->prev->next = input_temp;
                list->tail->prev = input_temp;
                list->counts++;
                print_list(list);
            }
            else if(before_after == 2){
                input_temp->prev = list->tail;
                input_temp->next = NULL;
                list->tail->next = input_temp;
                list->tail = input_temp;
                list->counts++;
                print_list(list);
            }
            else{
                printf("No such choose !\n");
            }
        }
    }
}
void delete_num(tNumStorHead *list) {
    int location = 0;
    if(list->counts == 0){
        printf("The list is empty\n");
        return;
    }
    tNumStorage *target_temp = list->head;
    printf("Specify a target location:");
    scanf("%d", &location);
    while(location < 1 || location > list->counts){
        printf("No such location !\n");
        printf("Specify a target location:");
        scanf("%d", &location);
        }
    if(location == 1 && list->counts == 1){
        list->head = NULL;
        list->tail = NULL;
        list->counts--;
        print_list(list);
    }
    else if(location == 1){
        list->head = list->head->next;
        list->head->prev = NULL;
        list->counts--;
        print_list(list);
    }
    else if(location != list->counts){
        for(int i = 1; i < location; i++){
            target_temp = target_temp->next;
        }
        target_temp->prev->next = target_temp->next;
        target_temp->next->prev = target_temp->prev;
        list->counts--;
        print_list(list);
    }
    else{
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        list->counts--;
        print_list(list);
    }
}