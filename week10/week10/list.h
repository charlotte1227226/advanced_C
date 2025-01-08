#ifndef __LIST_H
#define __LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef struct num_storage {
    int number;
    struct num_storage *next;
    struct num_storage *prev;
} tNumStorage;
typedef struct num_stor_head {
    int counts;
    struct num_storage *head;
    struct num_storage *tail;
} tNumStorHead;

tNumStorHead *initial_list(tNumStorHead *list);

void print_list(tNumStorHead *list);
void list_insert(tNumStorHead *list, int input, int location, int before_after);
void list_delete(tNumStorHead *list, int location);

#endif
