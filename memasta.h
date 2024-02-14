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

typedef struct mm_List
{
     struct mm_seg *head;
     struct mm_seg *tail;
}mm_list;

void* mm_alloc(size_t size);

void mm_free(void* seg);

void mm_list_init(struct mm_List l);

void mm_list_deinit(struct mm_List l);

void mm_list_push(mm_list *l, struct mm_seg *n);

void mm_list_pop(mm_list *l);

