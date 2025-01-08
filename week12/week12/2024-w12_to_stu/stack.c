#include "stack.h"

tStack *create_stack(void)
{
    tStack* Stack = (tStack*)malloc(sizeof(tStack));
    Stack->count = 0;
    Stack->head = NULL;
    return Stack;
}

void handle_push_operation(tStack *stack_ptr)
{
    if(stack_ptr->count == N){
	    printf ("[Error]  handle_push_operation(): space full \n");
        return;
    }
    printf("  handle_push_operation(): enter score value: ");
    int score = 0;
    tNode* node = (tNode*)malloc(sizeof(tNode));
    scanf("%d", &score);
    //printf("%d\n", node->data_ptr->score);
    //printf("%d\n", node->data_ptr->loc);
    get_score_space(&(node->data_ptr));
    node->data_ptr->score = score;
    //printf("%d\n", node->data_ptr->score);
    //printf("%d\n", node->data_ptr->loc);
    node->next = stack_ptr->head;
    stack_ptr->head = node;
    stack_ptr->count++;
}

void handle_pop_operation(tStack *stack_ptr)
{
    if(stack_ptr->count == 0){
	    printf ("[Error]  handle_pop_operation(): nothing in stack \n");
        return;
    }
    tNode* node = stack_ptr->head;
    printf("  handle_pop_operation(): poped value: %d\n", node->data_ptr->score);
	return_score_space(node->data_ptr->loc);
    stack_ptr->head = stack_ptr->head->next;
    stack_ptr->count--;
}

void print_stack_content(tStack *stack_ptr)
{
    printf("   print_stack_content(): stack items -> ");
    tNode* node = stack_ptr->head;
    while(node != NULL){
        printf("%d(%d) ", node->data_ptr->score, node->data_ptr->loc);
        node = node->next;
    }
    printf("\n");
}

