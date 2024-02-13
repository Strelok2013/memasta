#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <alloca.h>
#include <stdio.h>
#include <string.h>

struct mm_seg
{
     size_t size;
     int* mem; // memory we're pointing to
     struct mm_seg* prev;
     struct mm_seg* next;
};


void* mm_alloc(size_t size);

void mm_free(void* seg);


