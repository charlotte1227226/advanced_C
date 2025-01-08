#include "space.h"

unsigned char buffer[SMALL_ELEMENT_SIZE*NUM_SMALL_BYTE_BUF + LARGE_ELEMENT_SIZE*NUM_LARGE_BYTE_BUF] = {0};
unsigned char byte_large_buf_mask = 0;
unsigned char byte_small_buf_mask = 0;
int change_location_map[NUM_SMALL_BYTE_BUF+NUM_LARGE_BYTE_BUF] = {0};
void print_buffer_status (void)
{
    int i;
    unsigned char mask = 0x80;
    printf ("      byte_small_buf_mask: ");
    for (i = 0; i< NUM_SMALL_BYTE_BUF; i++)
    {
        printf ("%d ", (byte_small_buf_mask & mask) >> (7-i));
        mask = mask >> 1;
    }
    printf ("\n");
    mask = 0x80;
    printf ("      byte_large_buf_mask: ");
    for (i = 0; i< NUM_LARGE_BYTE_BUF; i++)
    {
        printf ("%d ", (byte_large_buf_mask & mask) >> (7-i));
        mask = mask >> 1;
    }
    printf ("\n");
}

void our_malloc(int type, void **target, int *mem_location)
{
    int location;

    if (byte_small_buf_mask == FULL && byte_large_buf_mask == FULL)
    {
        return ;
    }
    else if (type == TYPE_SMALL)
    {
        location = test_single_location(byte_small_buf_mask, NUM_SMALL_BYTE_BUF);
        if (location >= 0)
        {
            set_single_bit(&byte_small_buf_mask, location);
            *target =  &buffer[SMALL_ELEMENT_SIZE*location];
            *mem_location = location;
            change_location_map[location] = 0;
        }
        else
        {
            location = test_single_location(byte_large_buf_mask, NUM_LARGE_BYTE_BUF);
            if (location >= 0)
            {
                set_single_bit(&byte_large_buf_mask, location);
                *target =  &buffer[LARGE_START + LARGE_ELEMENT_SIZE*location];
                *mem_location = location;
                change_location_map[location] = 1;
            }
            else
            {
                return ;
            }
        }
    }
    else
    {

        location = test_single_location(byte_large_buf_mask, NUM_LARGE_BYTE_BUF);
        if (location >= 0)
        {
            set_single_bit(&byte_large_buf_mask, location);
            *target =  &buffer[LARGE_START + LARGE_ELEMENT_SIZE*location];
            *mem_location = location;
            change_location_map[NUM_SMALL_BYTE_BUF+location] = 0;
        }
        else
        {
            location = test_dual_location(byte_small_buf_mask, NUM_SMALL_BYTE_BUF);
            if (location >= 0)
            {
                set_dual_bit(&byte_small_buf_mask, location);
                *target =  &buffer[SMALL_ELEMENT_SIZE*location];
                *mem_location = location;
                change_location_map[NUM_SMALL_BYTE_BUF+location]  = 1;
            }
            else
            {
                return ;
            }
        }
    }    
}

int test_single_location(unsigned char mask, int mask_length)
{
    unsigned char set = 0x01;
    int test = 0;
    int location = 0;
    for(int i = 0; i < mask_length; i++)
    {
        test = mask & set;
        if(test == 0)
        {
            return location;
        }
        else
        {
            set = set << 1;
            location++;
        }
    }
    return -1;
}

void set_single_bit(unsigned char *mask, int location)
{
    unsigned char set = 0x01 << location;
    *mask = *mask | set;
}

int test_dual_location(unsigned char mask, int mask_length)
{
    unsigned char set = 0x01;
    int test = 0;
    int location = 0;
    for(int i = 0; i < mask_length - 1; i++)
    {
        test = mask & set;
        if(test == 0)
        {
            unsigned char next_set = set << 1;
            test = mask & next_set;
            if(test == 0)
            {
                //printf("here\n");
                return location;
            }
            //printf("saghduaysihdgh\n");
        }
        set = set << 1;
        location++;
    }
    //printf("sssss\n");
    return -1;
}

void set_dual_bit(unsigned char *mask, int location)
{
    unsigned char set = 0x03 << location;
    *mask = *mask | set;
}

void clear_single_bit(unsigned char *mask, int location)
{
    unsigned char set = 0x01 << location;
    *mask = *mask & (~set);
}

void clear_dual_bit(unsigned char *mask, int location)
{
    unsigned char set = 0x03 << location;
    *mask = *mask & (~set);
}

void our_free(int type, int mem_location)
{
    if(type == TYPE_SMALL)
    {
        if(change_location_map[mem_location] == 0)
        {
            clear_single_bit(&byte_small_buf_mask, mem_location);
        }
        else if(change_location_map[mem_location] == 1)
        {
            clear_single_bit(&byte_large_buf_mask, mem_location);
            change_location_map[mem_location] = 0;
        }
    }
    else if(type == TYPE_LARGE)
    {
        if(change_location_map[NUM_SMALL_BYTE_BUF+mem_location] == 0)
        {
            clear_single_bit(&byte_large_buf_mask, mem_location);
        }
        else if(change_location_map[NUM_SMALL_BYTE_BUF+mem_location] == 1)
        {
            clear_dual_bit(&byte_small_buf_mask, mem_location);
            change_location_map[NUM_SMALL_BYTE_BUF+mem_location] = 0;
        }
    }
}
