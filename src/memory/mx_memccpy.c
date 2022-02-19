#include "mem.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
    register byte t;
    register byte *dest = (byte *)dst;
    register const byte *source = (const byte *)src;

    for (unsigned i = 0; i < n; i++)
    {
        dest[i] = t = source[i];
        if (t == '\0')
            break;
        if (t == c)
            return &dest[i + 1];
    }
    return NULL;
}
