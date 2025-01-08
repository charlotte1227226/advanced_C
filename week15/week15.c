#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4

typedef char my_int[MAX];

void my_add(my_int result, my_int input1, my_int input2);
void my_number_print(my_int input);
void trans_from_string(my_int input, char *user_input);

int main() {
    char user_input1[MAX + 1]; 
    char user_input2[MAX + 1];
    my_int input1 = {0};
    my_int input2 = {0};
    my_int result = {0};
    while (1) {
        printf("Please give a number less than 4: ");
        scanf("%s", user_input1);
        if (strlen(user_input1) <= MAX) {
            break;
        } else {
            printf("The number is too large! Re-enter!!\n");
        }
    }
    trans_from_string(input1, user_input1);
    while (1) {
        printf("Please give another number less than 4: ");
        scanf("%s", user_input2);
        if (strlen(user_input2) <= MAX) {
            break;
        } else {
            printf("The number is too large! Re-enter!!\n");
        }
    }
    trans_from_string(input2, user_input2);
    my_add(result, input1, input2);
    my_number_print(result);

    return 0;
}

void trans_from_string(my_int input, char *user_input) {
    int len = strlen(user_input);
    for (int i = 0; i < MAX; i++) {
        if (i < MAX - len) {
            input[i] = '0'; 
        } 
        else {
            input[i] = user_input[i - (MAX - len)];
        }
    }
}


void my_add(my_int result, my_int input1, my_int input2) {
    int carry = 0;
    for (int i = MAX - 1; i >= 0; i--) { 
        int a = input1[i] - '0';
        int b = input2[i] - '0';
        int sum = a + b + carry;
        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }
        result[i] = sum + '0';
    }
    if (carry == 1) {
        printf("Overflow! The result exceeds %d digits.\n", MAX);
        exit(1);
    }
}

void my_number_print(my_int input) {
    int leading_zero = 1;
    for (int i = 0; i < MAX; i++) {
        if (leading_zero && input[i] == '0') {
            continue; 
        }
        leading_zero = 0;
        printf("%c", input[i]);
    }
    if (leading_zero) {
        printf("0");
    }
    printf("\n");
}
