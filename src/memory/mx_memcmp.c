#include "mem.h"

int mx_memcmp(const void *restrict s1, const void *restrict s2, size_t n)
{
    if (n != 0)
    {
        register const ubyte *p1 = s1, *p2 = s2;
        while (n-- != 0)
        {
            if (*p1++ != *p2++)
                return (*--p1 - *--p2);
        }
    }
    return 0;
}
