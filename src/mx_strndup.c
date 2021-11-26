#include "libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    size_t len;
    char *copy;

    for (len = 0; len < n && s1[len]; len++)
        continue;

    if ((copy = malloc(len + 1)) == NULL)
        return (NULL);
    mx_memcpy(copy, s1, len);
    copy[len] = '\0';
    return (copy);
}
