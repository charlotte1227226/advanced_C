#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char sequence[80];
    int i;
    int j;
    int count=0;
    printf("Please input a character sequence: ");
    scanf("%s",sequence);
    int length = strlen(sequence);
    for(i=0;i<length-1;i++){
        for(j=i+1;j<length;j++){
            if(sequence[i]>sequence[j]){
                count++;
            }
        }
    }
    printf("number of inversions:%d\n",count);
    system("pause");
    return 0;
}