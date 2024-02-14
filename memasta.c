#include "memasta.h"


void* mm_alloc(size_t size)
{

    printf("attempting to allocate %zu bytes of memory \n", size);
    int *ptr = malloc(size);
    if(!ptr)
    {
        printf("Failed to allocate %zu bytes of memory, out of memory? \n", size);
    }
    struct mm_seg* seg = (void*)ptr;
    seg->mem = ptr;
    seg->size = size;
    seg->next = NULL;
    seg->prev = NULL;

    return seg;
}

void mm_list_init(struct mm_List l)
{
    memset(&l, 0, sizeof l);
}

void mm_list_push(mm_list *l, struct mm_seg *n)
{
    printf("Addr of list in push func: %p \n", &l);
    if(!n)
    {
       return;
    }

    if(!l->head)
    {
        l->head = n;
    }
    else
    {
        if(!l->tail)
        {
            n->prev = l->head;
            l->head->next = n;
            l->tail = n;
        }
        else
        {
            n->prev = l->tail;
            l->tail->next = n;
            l->tail = n;
        }
    }
}

void mm_list_pop(mm_list *l)
{
    printf("Addr of list in pop func: %p \n", &l);
    if(!l->tail)
    {
        if(l->head)
        {
            mm_free(l->head);
        }
        return;
    }

    l->tail->prev->next = NULL;
    mm_free(l->tail);
}



void mm_free(void* seg)
{
    struct mm_seg* seg_p = (struct mm_seg*) seg;
    // Potential for some kind of check that checks for pointer type?
    printf("Freeing %zu bytes of memory \n", seg_p->size);
    free(seg);
}

int main(void)
{
    mm_list list = {0};
    mm_list_init(list);

    printf("Addr of list: %p \n", &list);

    mm_list_push(&list, mm_alloc(64));
    mm_list_pop(&list);

    printf("End of test \n");
}
