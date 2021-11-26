#include "libmx.h"

// void *mx_realloc(void *ptr, size_t size)
// {
//     void *new_ptr = NULL;
//     size_t old_size = mx_malloc_size(ptr);

//     if (ptr == NULL)
//         return malloc(size);
//     else if (size && (new_ptr = malloc(MX_MAX(size, old_size, size_t))))
//         mx_memcpy(new_ptr, ptr, old_size);
//     if (old_size)
//         free(ptr);
//     return new_ptr;
// }

void *mx_realloc(void *ptr, size_t size)
{
    void *new_ptr;
    size_t current_size = mx_malloc_size(ptr);
    if (!ptr)
    {
        return malloc(size);
    }

    if (size <= current_size)
    {
        return ptr;
    }

    new_ptr = malloc(size);
    mx_memmove(ptr, new_ptr, current_size);
    free(ptr);
    return new_ptr;
}