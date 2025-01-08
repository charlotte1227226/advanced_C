#include "ui.h"
#include "list.h"

void ui_main_menu(tNumStorHead *list) {
    int input = 0, location = 0, before_after = 0;
    int opt = 0;
    printf("1. Add a number or 2. Delete a number:");
    scanf("%d", &opt);
    if (opt == 1) {
        ui_add_menu(list, input, location, before_after);
    } else if (opt == 2) {
        ui_del_menu(list);
    } else {
        printf("No such choose!\n");
    }
    print_list(list);
}

void ui_add_menu(tNumStorHead *list, int input, int location, int before_after) {
    printf("Add a number:");
    scanf("%d", &input);
    if (list->counts != 0) {
        ui_get_add_location(list, &location, &before_after);
    }
    list_insert(list, input, location, before_after);
}

void ui_get_add_location(tNumStorHead *list, int *location, int *before_after) {
    printf("Specify a target location:");
    scanf("%d", location);
    while (*location < 1 || *location > list->counts) {
        printf("No such location!\n");
        printf("Specify a target location:");
        scanf("%d", location);
    }
    printf("1. Before or 2. After the location %d:", *location);
    scanf("%d", before_after);
    while (*before_after != 1 && *before_after != 2) {
        printf("No such choice!\n");
        printf("1. Before or 2. After the location %d:", *location);
        scanf("%d", before_after);
    }
}

void ui_del_menu(tNumStorHead *list) {
    if (list->counts == 0) {
        printf("The list is empty\n");
        return;
    }
    int location = ui_get_del_location();
    while (location < 1 || location > list->counts) {
        printf("No such location!\n");
        location = ui_get_del_location();
    }
    list_delete(list, location);
}

int ui_get_del_location() {
    int location = 0;
    printf("Specify a target location:");
    scanf("%d", &location);
    return location;
}
