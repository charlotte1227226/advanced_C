#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct num_list{
    int counts;
    int *p_list;
}tNumList;

void fill_list(tNumList *list);
void bubble_sort(tNumList *list);
void merge(tNumList *list1, tNumList *list2);
void print_list(tNumList *list);

int main(){
    tNumList *list1,*list2;
    list1 = (tNumList *)malloc(sizeof(tNumList));
    list2 = (tNumList *)malloc(sizeof(tNumList));
    printf("Please enter how many numbers in list1:");
    fill_list(list1);
    printf("Please enter how many numbers in list2:");
    fill_list(list2);
    bubble_sort(list1);
    bubble_sort(list2);
    printf("sorted list1:");
    print_list(list1);
    printf("sorted list2:");
    print_list(list2);
    merge(list1,list2);
    return 0;
}

void fill_list(tNumList *list){
    scanf("%d",&list->counts);
    list->p_list=(int *)malloc(sizeof(int)*list->counts);
    printf("Please input %d number:",list->counts);
    for(int i=0;i<list->counts;i++){
        scanf("%d",&list->p_list[i]);
    }
}

void bubble_sort(tNumList *list) {
    for (int i=0; i<list->counts-1; i++) {
        for (int j=0; j<list->counts-i-1; j++) {
            if (list->p_list[j] > list->p_list[j+1]) {
                int temp = list->p_list[j];
                list->p_list[j] = list->p_list[j+1];
                list->p_list[j+1] = temp;
            }
        }
    }
}
void merge(tNumList *list1, tNumList *list2) {
    int list1_counter=0;
    int list2_counter=0;
    while (list1_counter<list1->counts||list2_counter<list2->counts){
        if(list1_counter<list1->counts&&list2_counter>=list2->counts){
            printf("%d ",list1->p_list[list1_counter]);
            list1_counter++;
        }
        else if(list1->p_list[list1_counter]<=list2->p_list[list2_counter]){
            printf("%d ",list1->p_list[list1_counter]);
            list1_counter++;
        }
        else{
            printf("%d ",list2->p_list[list2_counter]);
            list2_counter++;
        }
    }
}

void print_list(tNumList *list){
     for (int i=0; i<list->counts; i++){
        printf("%d ",list->p_list[i]);
     }
     printf("\n");
}