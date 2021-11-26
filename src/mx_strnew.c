#include "libmx.h"

char *mx_strnew(const int size)
{
    char *new_string;

    if (size >= 0)
    {
        new_string = malloc(size + 1);
        for (int i = 0; i <= size; i++)
            new_string[i] = '\0';
        return new_string;
    }
    return NULL;
}
