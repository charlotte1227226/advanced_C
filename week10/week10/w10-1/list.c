#include "list.h"

tNumStorHead *initial_list(tNumStorHead *list) {
    list = (tNumStorHead *)malloc(sizeof(tNumStorHead));
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void print_list(tNumStorHead *list) {
    tNumStorage *node_ptr = list->head;
    printf("\n");
    printf("counts: %d\n", list->counts);
    printf("From head --> ");
    while (node_ptr != NULL) {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }
    node_ptr = list->tail;
    printf("\nFrom tail --> ");
    while (node_ptr != NULL) {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->prev;
    }
    printf("\n\n");
}
void list_insert(tNumStorHead *list, int input, int location, int before_after) {
    tNumStorage *input_temp = (tNumStorage *)malloc(sizeof(tNumStorage));
    input_temp->number = input;
    input_temp->next = NULL;
    input_temp->prev = NULL;

    if (list->counts == 0) {
        list->head = input_temp;
        list->tail = input_temp;
    } 
    else if (location == 1) { 
        if (before_after == 1) { 
            input_temp->next = list->head;
            list->head->prev = input_temp;
            list->head = input_temp;
        }
        else {
            input_temp->next = list->head->next;
            input_temp->prev = list->head;
            if (list->head->next != NULL) {
                list->head->next->prev = input_temp;
            }
            list->head->next = input_temp;
            if (list->counts == 1) {
                list->tail = input_temp;
            }
        }
    } 
    else if (location == list->counts) { 
        if (before_after == 2) { 
            input_temp->prev = list->tail;
            list->tail->next = input_temp;
            list->tail = input_temp;
        }
        else {
            input_temp->prev = list->tail->prev;
            input_temp->next = list->tail;
            list->tail->prev->next = input_temp;
            list->tail->prev = input_temp;
        }
    } 
    else {
        tNumStorage *target_temp = list->head;
        for (int i = 1; i < location; i++) {
            target_temp = target_temp->next;
        }
        if (before_after == 1) {
            input_temp->prev = target_temp->prev;
            input_temp->next = target_temp;
            target_temp->prev->next = input_temp;
            target_temp->prev = input_temp;
        }
        else {
            input_temp->prev = target_temp;
            input_temp->next = target_temp->next;
            target_temp->next->prev = input_temp;
            target_temp->next = input_temp;
        }
    }
    list->counts++;
}
void list_delete(tNumStorHead *list, int location) {
    if (list->counts == 0) return; 
    tNumStorage *target_temp = list->head;
    if (location == 1) {
        if (list->counts == 1) {
            list->head = NULL;
            list->tail = NULL;
        } else {
            list->head = list->head->next;
            list->head->prev = NULL;
        }
    } else if (location == list->counts) {
        target_temp = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    } else {
        for (int i = 1; i < location; i++) {
            target_temp = target_temp->next;
        }
        target_temp->prev->next = target_temp->next;
        target_temp->next->prev = target_temp->prev;
    }

    list->counts--;
}

