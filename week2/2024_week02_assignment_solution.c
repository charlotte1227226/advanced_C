#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char *argv[]) {
    argv+=2;
    int length=argc-2;
    int *list=(int *)malloc(sizeof(int)* length);
    int *p,*k;
    p=list;
    k=list;
    for (int i=0; i<length; i++) {
        *list=atoi(*argv);
        argv++; 
        list++;
    }
    int i=0,j=0;
    list=p;
    int row=sqrt(length);
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            printf("%d\t",*list);
            list++;
        }
        printf("\n");
    }
    printf("\n");
    list=p;
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            if(i==0){
                int temp;
                temp =*list;
                *list=*(list+row*2);
                *(list+row*2)=temp;
                }
            printf("%d\t",*list);
            list++;
        }
        printf("\n");
    }
    printf("\n");
    list=p;
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            if(j==0){
                int temp;
                temp =*list;
                *list=*(list+2);
                *(list+2)=temp;
                }
            printf("%d\t",*list);
            list++;
        }
        printf("\n");
    }
    return 0;
}