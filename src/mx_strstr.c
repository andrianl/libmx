#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle)                                /* Substring to try to find in string. */
{
    register char *a, *b;

    /* First scan quickly through the two strings looking for a
     * single-character match.  When it's found, then compare the
     * rest of the substring.
     */

    b = (char *)needle;
    if (*b == 0)
    {
        return (char *)haystack;
    }
    for (; *haystack != 0; haystack += 1)
    {
        if (*haystack != *b)
        {
            continue;
        }
        a = (char *)haystack;
        while (1)
        {
            if (*b == 0)
            {
                return (char *)haystack;
            }
            if (*a++ != *b++)
            {
                break;
            }
        }
        b = (char *)needle;
    }
    return NULL;
}
