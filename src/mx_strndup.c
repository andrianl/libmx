#include "libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    size_t slen = (size_t)mx_strlen(s1);
    int len = slen < n ? slen : n;
    char *copy = malloc(len + 1);
    if (copy)
    {
        mx_memcpy(copy, s1, len);
        copy[len] = '\0';
    }
    return copy;
}
