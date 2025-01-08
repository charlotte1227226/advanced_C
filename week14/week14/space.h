#ifndef __SPACE__
#define __SPACE__

#include "main.h"

#define NUM_BYTE_BUF      23
#define UNIT_ELEMENT_SIZE      32
#define FULL              255

void print_buffer_status(void);
void our_malloc(int type, void **target, int *mem_location);
void our_free(int mem_location, int data_type);  
int test_location(unsigned int mask, int mask_length, int data_type);
void set_bit(unsigned int *mask, int location, int data_type);
void clear_bit(unsigned int *mask, int location, int data_type);


#endif