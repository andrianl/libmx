//#include <stdio.h>

char *mx_strcpy(char *dst, const char *src)
{
    char *save = dst;

    for (; (*dst = *src); ++src, ++dst)
        ;
    return (save);
}
