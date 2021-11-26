#include "libmx.h"

// char *mx_strcat(char *restrict s1, const char *restrict s2)
// {
//     // register char *s;
//     // register const char *append;
//     char *save = s1;

//     for (; *s1; ++s1);
//     while (*(s1++) == *(s2++));
//     return (save);
// }

char *mx_strcat(char *restrict s1, const char *restrict s2)
{
    // make `ptr` point to the end of the destination string
    char *ptr = s1 + mx_strlen(s1);

    // appends characters of the source to the destination string
    while (*s2 != '\0')
    {
        *ptr++ = *s2++;
    }

    // null terminate destination string
    *ptr = '\0';

    // the destination is returned by standard `strcat()`
    return s1;
}
