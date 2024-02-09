#include "memasta.h"

int* mm_alloc(size_t size)
{

    int *ptr = malloc(size);

    printf("int* ptr: %p \n", ptr);
    printf("attempting to allocate %zu bytes of memory \n", size);
    // int* ptr = malloc(size);
    if(!ptr)
    {
        printf("Failed to allocate %zu bytes of memory, out of memory? \n", size);
        return ptr;
    }
    return ptr;
}

void mm_free(int* ptr)
{
    size_t size = sizeof ptr;
     free(ptr);
     printf("Freed %zu bytes of memory \n", size);
}

int main(void)
{
    int* test_memory = mm_alloc(64);

    mm_free(test_memory);

    printf("End of test \n");
}
