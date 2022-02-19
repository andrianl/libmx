#include "mem.h"

void *mx_memmove(void *restrict dst, const void *restrict  src, unsigned long len)
{
    register byte *dest = dst;
    register byte const *source = src;
    if (source < dest)
        /* Moving from low mx_mem to hi mx_mem; start at end.  */
        for (source += len, dest += len; len; --len)
            *--dest = *--source;
    else if (source != dest)
    {
        /* Moving from hi mx_mem to low mx_mem; start at beginning.  */
        //for (; len; --len)
        while (len--)
            *dest++ = *source++;
    }
    return dst;
}
