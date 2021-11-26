//#include <stdio.h>

char *mx_strcpy(char *dst, const char *src)
{
    char *save = dst;

    for (; (*dst = *src); ++src, ++dst)
        ;
    return (save);
}

// int main()
// {
//     char *dst;
//     const char *src = "Hello World";
//     mx_strcpy(dst, src);
//     printf("%s\n", dst);
//     return 0;
// }
