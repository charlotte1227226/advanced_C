#include "space.h"

unsigned char buffer[UNIT_ELEMENT_SIZE*NUM_BYTE_BUF];
unsigned int byte_buf_mask = 0;

void print_buffer_status (void)
{
    int i;
    unsigned int mask = 1 << (NUM_BYTE_BUF - 1);
    // unsigned int mask = 0x80000000;
    printf ("      byte_buf_mask: ");
    for (i = 0; i < NUM_BYTE_BUF; i++)
    {
        printf ("%d ", (byte_buf_mask & mask) >> (NUM_BYTE_BUF - 1 - i));
        mask = mask >> 1;
        if(i % 8 == 6)
        {
            printf (", ");
        }
        // if(i ==  NUM_BYTE_BUF)
        // {
        //     break;
        // }
    }
    printf ("\n");
}

void our_malloc(int type, void **target, int *mem_location)
{
    int location;

    if (byte_buf_mask == FULL){
        return;
    }
    else if (type >= 1 && type <= UNIT_ELEMENT_SIZE)
    {
        location = test_location(byte_buf_mask, NUM_BYTE_BUF, type);
        if (location >= 0)
        {
            set_bit(&byte_buf_mask, location, type);
            *target =  &buffer[UNIT_ELEMENT_SIZE*location];
            *mem_location = location;
        }
        else
        {
            return ;
        }
    }
    else
    {
        return;
    }    
}

int test_location(unsigned int mask, int mask_length, int data_type)
{
    unsigned int set = 0x00000001;
    unsigned int bound = 0xFFFFFFFF << (mask_length);
    int test = 0;
    int count = 0;
    int location = 0;
    for (int i = 0; i < data_type - 1; i++)
    {
        int new_set = set << 1;
        set = set | new_set;
    }
    for(int i = 0; i < mask_length ; i++)
    {
        test = (bound | mask) & set;//0xFF800000 | mask
        if(test == 0)
        {
            return location;
        }
        set = set << 1;
        location++;
    }
    //printf("sssss\n");
    return -1;
}

void set_bit(unsigned int *mask, int location, int data_type)
{
    unsigned int set = 0x00000001 ;
    for (int i = 0; i < data_type - 1; i++)
    {
        int new_set = set << 1;
        set = set | new_set;
    }
    set = set << location;
    *mask = *mask | set;
}
void clear_bit(unsigned int *mask, int location, int data_type)
{
    unsigned int set = 0x00000001 ;
    for (int i = 0; i < data_type - 1; i++)
    {
        int new_set = set << 1;
        set = set | new_set;
    }
    set = set << location;
    *mask = *mask & (~set);
}

void our_free(int mem_location, int data_type)
{
    clear_bit(&byte_buf_mask, mem_location, data_type);
}
