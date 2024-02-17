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





void mm_free(void* seg)
{
    if(!seg)
    {
        printf("Attempting to free a null pointer\n");
        return;
    }
    struct mm_seg *seg_p = seg;
    seg_p->next = NULL; // this shouldn't be done here methinks
    printf("Freeing %zu bytes of memory\n", seg_p->size);
    free(seg);
    seg = 0;
}

int main(void)
{
    void* ptr_1 = mm_alloc(0);
    void* ptr_2 = mm_alloc(16);
    void* ptr_3 = mm_alloc(64);

    mm_free(ptr_1);
    mm_free(ptr_2);
    mm_free(ptr_3);


    printf("End of test \n");
}
