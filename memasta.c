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


void mm_free(void* seg)
{
    struct mm_seg* seg_p = (struct mm_seg*) seg;
    // Potential for some kind of check that checks for pointer type?
    printf("Freeing %zu bytes of memory \n", seg_p->size);
    free(seg);
}

int main(void)
{
    printf("End of test \n");
}
