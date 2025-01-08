#include<stdio.h>
typedef unsigned int Int32;

int check_range_loop(Int32 input, Int32 high, Int32 low);
int check_range_no_loop(Int32 input, Int32 high, Int32 low);

int main(){
    Int32 input;
    Int32 high;
    Int32 low;
    printf("Please specify the input:");
    scanf("%x", &input);
    printf("    Please specify the high: ");
    scanf("%d", &high);
    printf("    Please specify the low: ");
    scanf("%d", &low);
    int loop_x, noloop_y;
    loop_x = check_range_loop(input, high, low);
    noloop_y = check_range_no_loop(input, high, low);
    printf("check_range_loop result: %d\n",loop_x);
    printf("check_range_no_loop result: %d\n",noloop_y);
    int Cont = 0;
    printf("Input 1 to keep trying the next round: ");
    scanf("%d", &Cont);
    while(Cont == 1){
        printf("Please specify the input:");
        scanf("%x", &input);
        printf("    Please specify the high:");
        scanf("%d", &high);
        printf("    Please specify the low: ");
        scanf("%d", &low);
        loop_x = check_range_loop(input, high, low);
        noloop_y = check_range_no_loop(input, high, low);
        printf("check_range_loop result: %d\n",loop_x);
        printf("check_range_no_loop result: %d\n",noloop_y);
        printf("Input 1 to keep trying the next round: ");
        scanf("%d", &Cont);
    }
    return 0;
}

int check_range_loop(Int32 input, Int32 high, Int32 low){
    Int32 set =0x00000001 << low;
    for(int i = low; i < high; i++){
        if(input & set){
            return 1;
        }
        else{
            set = set << 1;
        }
    }
    return 0;
}

int check_range_no_loop(Int32 input, Int32 high, Int32 low){
    Int32 set1 = 0xFFFFFFFF << low;
    Int32 set2 = 0xFFFFFFFF << high;
    Int32 set = set1 ^ set2;
    if(input & set){
        return 1;
    }
    else{
        return 0;
    }
}