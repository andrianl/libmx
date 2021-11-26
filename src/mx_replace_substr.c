#include "libmx.h"

// You must free the result if result is non-NULL.
char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace)
{
    char *result;  // the return string
    char *ins;     // the next insert point
    char *tmp;     // varies
    int len_rep;   // length of rep (the string to remove)
    int len_with;  // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;     // number of replacements

    // sanity checks and initialization
    if (!str || !sub)
        return NULL;
    len_rep = mx_strlen(sub);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!replace)
        replace = "";
    len_with = mx_strlen(replace);

    // count the number of replacements needed
    ins = (char *)str;
    for (count = 0; (tmp = mx_strstr(ins, sub)); ++count)
    {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(mx_strlen(str) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--)
    {
        ins = mx_strstr(str, sub);
        len_front = ins - str;
        tmp = mx_strncpy(tmp, str, len_front) + len_front;
        tmp = mx_strcpy(tmp, replace) + len_with;
        str += len_front + len_rep; // move to next "end of rep"
    }
    mx_strcpy(tmp, str);
    return result;
}
