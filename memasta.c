#include "memasta.h"


void* mm_alloc(size_t size)
{
    if(size == 0)
    {
        printf("Attempted to allocate 0 Bytes \n");
        return 0;
    }
    else
    {
        printf("Allocating: %zu bytes\n ", size);

    int* ptr = malloc(sizeof(struct mm_seg) + size);

    if(!ptr)
    {
        return 0;
    }

    struct mm_seg *seg = (void*)ptr;
    seg->next = NULL;
    seg->prev = NULL;
    seg->size = size;

    return seg; // Sane????
    }
}


void mm_list_init(struct mm_List *l)
{
    memset(l, 0, sizeof(mm_list));
    l->head = NULL;
    l->tail = NULL;

}

void mm_list_push(mm_list* l, struct mm_seg* a)
{
    mm_list_insert(l, l->tail, a);
    // Also sane???
}


void mm_list_insert(mm_list* l, struct mm_seg* n, struct mm_seg* a)
{
    if(!l->head)
    {
        l->head = a;
        return;
    }
    else
    {
        if(!l->tail)
        {
            l->head->next = a;
            a->prev = l->head;
            l->tail = a;
            return;
        }
    }

    if(n == l->head)
    {
        l->head->prev = a;
        a->next = l->head;
        l->head = a;
        return;
    }
    if(n == l->tail)
    {
        l->tail->next = a;
        a->prev = l->tail;
        l->tail =  a;
        return;
    }

    n->next->prev = a;
    a->next = n->next;
    n->next = a;
    a->prev = n;
    // Hopefully its sane...

}


void mm_list_pop(mm_list* l)
{
    if(!l->tail)
    {
        mm_free(l->head);
        l->head = NULL;
        return;
    }
    if(l->tail->prev == l->head)
    {

        mm_free(l->tail);
        l->head->next = NULL;
        l->tail = NULL;
        return;
    }
    void* tmp = l->tail->prev;
    mm_free(l->tail);
    l->tail = tmp;
    l->tail->next = NULL;
}

void mm_list_deinit(struct mm_List* l)
{

}


void mm_free(void* seg)
{
    if(!seg)
    {
        printf("Attempting to free a null pointer\n");
        return;
    }
    struct mm_seg *seg_p = seg;
    // seg_p->next = NULL; // this shouldn't be done here methinks
    printf("Freeing %zu bytes of memory\n", seg_p->size);
    free(seg);
    seg = 0;
}

int main(void)
{
    mm_list list;

    mm_list_init(&list);


    // printf("Head addr: %p \n", list.head);
    // printf("Tail addr: %p \n", list.tail);
    mm_list_push(&list, mm_alloc(64));
    // printf("Value of list head: %p \n", list.head);
    // printf("Value of list tail: %p \n", list.tail);
    mm_list_push(&list, mm_alloc(32));
    mm_list_push(&list, mm_alloc(8));
    mm_list_push(&list, mm_alloc(16));
    mm_list_push(&list, mm_alloc(24));
    mm_list_pop(&list);
    mm_list_pop(&list);
    mm_list_pop(&list);
    mm_list_pop(&list);
    mm_list_pop(&list);
    // printf("Addr of head->next: %p \n", list.head->next);
    // printf("Addr of tail: %p \n", list.tail);
    // void* ptr_1 = mm_alloc(0);
    // void* ptr_2 = mm_alloc(16);
    // void* ptr_3 = mm_alloc(64);
    //
    // mm_free(ptr_1);
    // mm_free(ptr_2);
    // mm_free(ptr_3);


    printf("End of test \n");
}
