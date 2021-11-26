#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n)
{
    if (n != 0)
    {
        register const unsigned char *p1 = s1, *p2 = s2;

        while (n)
        {
            if (*p1++ != *p2++)
                return (*--p1 - *--p2);
        }
    }
    return (0);
}

// do
// {
//     if (*p1++ != *p2++)
//         return (*--p1 - *--p2);
// } while (--n != 0)

// int mx_memcmp(const void *s1, const void *s2, size_t n)
// {
//     register const unsigned char *str1 = s1;
//     register const unsigned char *str2 = s2;
//     while (n-- > 0)
//     {
//         if (*str1++ != *str2++)
//            // return str1[-1] < str2[-1] ? -1 : 1;
//             return  (*str1 - *str2);
//     }
//     return 0;
// }
