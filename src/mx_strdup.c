#include "libmx.h"

char *mx_strdup(const char *s1)
{
    size_t siz;
    char *copy;
    siz = mx_strlen(s1) + 1;
    if ((copy = malloc(siz)) == NULL)
        return (NULL);
    (void)mx_memcpy(copy, s1, siz);
    return (copy);
}
