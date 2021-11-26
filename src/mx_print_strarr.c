#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim)
{
    if (!delim || !arr || !*arr)
        return;

    for (mx_printstr(*arr); *++arr; mx_printstr(*arr))
        mx_printstr(delim);
    write(1, "\n", 1);
}
