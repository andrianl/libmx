#include "str.h"

bool mx_isalpha(char c)
{
    return (c > 64 && c < 91) || (c > 96 && c < 123);
}

bool mx_isdigit(char c)
{
    return (c > 47 && c < 58);
}

bool mx_islower(char c)
{
    return (c > 96 && c < 123);
}

bool mx_isspace(char c)
{
    return c == ' ' || (c > 8 && c < 14);
}

bool mx_isupper(char c)
{
    return (c > 64 && c < 91);
}

char mx_tolower(char c)
{
    return mx_isupper(c) ? c + 32 : c;
}

char mx_toupper(char c)
{
    return mx_islower(c) ? c - 32 : c;
}
