#include "mem.h"
#include <stddef.h>

void *mx_memrchr(const void *s, int c, unsigned long n)
{
    register byte *ptr = (byte *)s;

    while (n--)
    {
        if (*(ptr + n) == c)
            return ptr + n;
    }
    return NULL;
}
