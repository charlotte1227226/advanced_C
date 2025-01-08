#ifndef __UI_H
#define __UI_H
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void ui_main_menu(tNumStorHead *list);
void ui_add_menu(tNumStorHead *list, int input, int location, int before_after);
void ui_get_add_location(tNumStorHead *list, int *location, int *before_after);
void ui_del_menu(tNumStorHead *list);
int ui_get_del_location(void);

#endif
