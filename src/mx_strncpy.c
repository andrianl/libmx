#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len)
{
    char *s = dst;
    while (len > 0 && *src != '\0')
    {
        *s++ = *src++;
        --len;
    }
    while (len > 0)
    {
        *s++ = '\0';
        --len;
    }
    return dst;
}
