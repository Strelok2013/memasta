#include "memasta.h"

void* mm_alloc(size_t size)
{

    printf("attempting to allocate %zu bytes of memory \n", size);
    int *ptr = malloc(size);
    // printf("int* ptr: %p \n", ptr);
    // int* ptr = malloc(size);
    if(!ptr)
    {
        printf("Failed to allocate %zu bytes of memory, out of memory? \n", size);
    }
    struct mm_seg* seg = (void*)ptr;
    seg->mem = ptr;
    seg->size = size;

    // printf("ptr: %p \n", ptr);

    // void* seg_r = ptr + sizeof *seg; // Unknown why it is necessary to create a new pointer by moving the pointer of ptr by the size of seg

    // printf("seg_r: %p \n", seg_r);

    return seg;
}

void mm_free(void* seg)
{
    struct mm_seg* seg_p = (struct mm_seg*) seg;
    // Potential for some kind of check that checks for pointer type?
    printf("Freeing %zu bytes of memory \n", seg_p->size);
    // void* seg_v = seg;
    // printf("Freeing an undetermined amount of memory \n");
    free(seg);
    // seg = NULL;
}

int main(void)
{
    struct mm_seg *test_seg = mm_alloc(64);

    // printf("Seg ptr: %p \n", test_seg);

    mm_free(test_seg);

    printf("End of test \n");
}
