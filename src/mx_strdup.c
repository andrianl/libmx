#include "libmx.h"

char *mx_strdup(const char *str)
{
    char *copy_str = mx_strnew(mx_strlen(str));
    return mx_strcpy(copy_str, str);
}
