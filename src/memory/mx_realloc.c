#include "mem.h"

#if defined(__APPLE__)
#include <malloc/malloc.h>
#define malloc_size(x) malloc_size(x)
#elif defined(_WIN64) || defined(_WIN32)
#include <malloc.h>
#define malloc_size(x) _msize(x)
#elif defined(__linux__)
#include <malloc.h>
#define malloc_size(x) malloc_usable_size(x)
#endif


void *mx_realloc(void *ptr, size_t size)
{

    if (!ptr)
    {
        return malloc(size);
    }

    unsigned current_size = malloc_size(ptr);

    if (size <= current_size)
    {
        return ptr;
    }

    void *new_ptr = malloc(size);
    mx_memmove(ptr, new_ptr, current_size);
    free(ptr);
    return new_ptr;
}
