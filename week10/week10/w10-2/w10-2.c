#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascending(char a, char b) {
    return a > b;
}
int descending(char a, char b) {
    return a < b;
}

void bubble_sort(char *input, int n, int (*ins_des)(char, char)) {
    char *p1, *p2, temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            p1 = input + j;
            p2 = input + j + 1;
            if (ins_des(*p1, *p2)) {
                temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
        }
    }
}

int main() {
    int order;
    char input[100];
    printf("Please enter (0) increasing or (1) decreasing sort: ");
    scanf("%d", &order);
    while(order != 0 && order != 1) {
        printf("Invalid input\n");
        printf("Please enter (0) increasing or (1) decreasing sort: ");
        scanf("%d", &order);
    }
    printf("Please enter a string: ");
    scanf("%s", input);
    int (*ins_des)(char, char);
    if (order == 0) {
        ins_des = ascending;
    } 
    else {
        ins_des = descending;
    }
    bubble_sort(input, strlen(input), ins_des);
    printf("Result: %s\n", input);
    return 0;
}
