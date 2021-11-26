#include "libmx.h"

void mx_str_reverse(char *str)
{
    char *p1, *p2;

    if (!str || !*str)
        return;
    //return str;
    for (p1 = str, p2 = str + mx_strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    //return str;
}
