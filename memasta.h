#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <alloca.h>
#include <stdio.h>

// #define MM_MAX_BUCKET_SIZE 1024

struct mm_seg
{
     size_t size;
     int* mem; // memory were pointing to
};

void mm_free(void* seg);

void* mm_alloc(size_t size);



// Simple as linked list
// #define list(t_) struct {t_* head; t_* tail;}



// This is probably the incorrect way to declare a custom type or something
// typedef struct mm_list(t_ something, )
// {
//
// };
