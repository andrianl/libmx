#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    char *csrc = (char *)src;
    char *cdst = (char *)dst;

    // char *ptr;
    while (n)
        *cdst++ = *csrc++;
    return dst;
}
