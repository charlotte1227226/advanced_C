#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "ui.h"

int main (void)
{
    tNumStorHead *list;
    list = initial_list(list);
    printf("Welcome to the linked list program!\n");
    while(1)
    {
        ui_main_menu(list);
    }
    return 0;
}