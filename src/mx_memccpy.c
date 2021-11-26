#include "libmx.h"

// void *mx_memccpy(void *dst, const void *src, int c, size_t n)
// {
//     void *last;

//     if (n == 0)
//     {
//         return NULL;
//     }

//     last = mx_memchr(src, c, n);

//     if (last == NULL)
//     {
//         mx_memmove(dst, src, n);
//         return NULL;
//     }
//     else
//     {
//         n = (char *)last - (char *)src + 1;
//         mx_memmove(dst, src, n);
//         return (void *)((char *)dst + n);
//     }
// }

void *mx_mempcpy(void *dest, const void *src, size_t len)
{
    return mx_memcpy(dest, src, len) + len;
}

void *mx_memccpy(void *dst, const void *src, int c, size_t n)
{
    void *p = mx_memchr(src, c, n);

    if (p != NULL)
        return mx_mempcpy(dst, src, p - src + 1);

    mx_memcpy(dst, src, n);
    return NULL;
}
