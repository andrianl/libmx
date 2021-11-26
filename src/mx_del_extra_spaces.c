#include "libmx.h"

char *mx_del_extra_spaces(const char *str)
{
    if (!str)
        return NULL;
    int i = 0;
    char *temp = mx_strnew(mx_strlen(str));

    while (str++)
    {
        if (!(mx_isspace(*str)))
        {
            temp[i] = str[i];
            i++;
        }
        if (!(mx_isspace(*str)) && mx_isspace(*(str + 1)))
            temp[i++] = ' ';
    }

    char *result = mx_strtrim(temp);
    mx_strdel(&temp);
    return result;
}
