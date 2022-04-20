#include "str.h"
#include "mem.h"
#include <stdlib.h>
#include <stddef.h>

char *mx_strnew(unsigned long size)
{
    // char *str = (char *)malloc(size + 1);
    // mx_memset(str, '\0', size + 1);
    char *str = (char *)mx_calloc(sizeof(char), size + 1);
    return str;
}

void mx_strdel(char **str)
{
    free(*str);
    *str = NULL;
}

char *mx_strtrim(const char *str)
{
    if (str)
    {
        int start = 0;
        int end = mx_strlen(str) - 1;

        while (mx_isspace(str[start]))
        {
            ++start;
        }

        while (mx_isspace(str[end]) && end > start)
        {
            --end;
        }

        char *new_str = mx_strnew(end > start ? end - start + 1 : 0);
        mx_strncpy(new_str, str + start, end - start + 1);
        return new_str;
    }
    return NULL;
}

int count_words(const char *str, char c)
{
    if (!str)
        return -1;

    int words = 0;

    while (*str)
    {

        while (*str && *str == c)
        {
            ++str;
        }

        if (*str && *str != c)
        {
            while (*str && *str != c)
            {
                ++str;
            }
            ++words;
        }
    }
    return words;
}

char **mx_strsplit(const char *s, char c)
{

    if (!s)
        return NULL;

    unsigned words, chars = 0;

    words = count_words(s, c);
    char **arr = (char **)malloc(sizeof(char *) * (words + 1));

    for (unsigned i = 0; i < words; i++)
    {
        chars = 0;
        while (*s == c && *s)
            s++;
        while (*s != c && *s)
        {
            chars++;
            s++;
        }
        arr[i] = malloc(sizeof(char) * (chars + 1));
        arr[i] = mx_strncpy(arr[i], s - chars, chars);
        arr[i][chars] = '\0';
    }
    arr[words] = NULL;

    if (arr)
        return arr;
    return NULL;
}

char *mx_strcat(char *restrict s1, const char *restrict s2)
{

    register char *ptr = s1 + mx_strlen(s1);

    while (*s2 != '\0')
    {
        *ptr++ = *s2++;
    }

    *ptr = '\0';

    return s1;
}

char *mx_strcpy(char *dst, const char *src)
{
    register char *save = dst;
    while ((*dst++ = *src++))
    {
    }
    return (save);
}

char *mx_strdup(const char *str)
{
    return mx_strcpy(mx_strnew(mx_strlen(str)), str);
}

char *mx_strndup(const char *s1, size_t n)
{
    unsigned slen = (unsigned)mx_strlen(s1);
    unsigned len = slen < n ? slen : n;
    char *copy = (char *)malloc(len + 1);
    mx_memcpy(copy, s1, len);
    copy[len] = '\0';
    return copy;
}

char *mx_strjoin(const char *s1, const char *s2)
{

    if (s1 == 0 && s2 == 0)
        return 0;
    if (s1 == 0)
        return mx_strdup(s2);
    if (s2 == 0)
        return mx_strdup(s1);

    char *new_str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

    new_str = mx_strcat(new_str, s1);
    new_str = mx_strcat(new_str, s2);

    return new_str;
}

char *mx_strncpy(char *restrict dst, const char *restrict src, int len)
{
    for (unsigned i = 0; src[i] != '\0' && len-- > 0; i++)
        dst[i] = src[i];
    return dst;
}

char *mx_strstr(const char *restrict haystack, const char *restrict needle)
{
    register char *a, *b;

    b = (char *)needle;
    if (*b == 0)
    {
        return (char *)haystack;
    }
    for (; *haystack != 0; haystack += 1)
    {
        if (*haystack != *b)
        {
            continue;
        }
        a = (char *)haystack;
        while (1)
        {
            if (*b == 0)
            {
                return (char *)haystack;
            }
            if (*a++ != *b++)
            {
                break;
            }
        }
        b = (char *)needle;
    }
    return NULL;
}

int mx_strcmp(const char *restrict s1, const char *restrict s2)
{
    while (*s1 == *s2++)
        if (*s1++ == '\0')
            return (0);
    return (unsigned char)*s1 - (unsigned char)*(s2 - 1);
}

int mx_strncmp(register const char *s1, register const char *s2, register size_t n)
{

    if (n == 0)
        return (0);
    while (n--)
    {
        if (*s1 != *s2++)
            return (*(unsigned char *)s1 - *(unsigned char *)--s2);
        if (*s1++ == 0)
            break;
    }
    return (0);
}

int mx_strlen(const char *str)
{
    register const char *ptr = str;

    while (*ptr)
    {
        ++ptr;
    }

    return (ptr - str);
}

void mx_str_reverse(char *str)
{
    int length = mx_strlen(str);

    for (register char *p1 = str, *p2 = str + length - 1; p2 > p1; ++p1, --p2)
    {
        if (*p1 == *p2)
            continue;

        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
}

char *concat_words(char **words)
{

    if (words == NULL)
        return NULL;

    char *result = "";
    char *step = NULL;

    for (unsigned i = 0; words[i] != NULL; i++)
    {
        if (i == 0)
            step = mx_strdup(words[i]);
        else
        {
            step = mx_strjoin(result, " ");
            mx_strdel(&result);

            result = mx_strjoin(result, step);
            mx_strdel(&step);

            step = mx_strjoin(result, words[i]);
            mx_strdel(&result);
        }
        result = mx_strjoin(result, step);
        mx_strdel(&step);
    }
    return result;
}

// int count_substr(const char *str, const char *sub)
// {
//     if (!str || !sub)
//         return -1;

//     if (mx_strcmp(sub, "") == 0)
//         return 0;

//     int length = mx_strlen(str);
//     unsigned sub_length = mx_strlen(sub);

//     if (char *_length >= sub_length)
//     {
//         unsigned result = 0;
//         for (bool is_sub; (str = mx_strchr(str, *sub)); str += is_sub ? 1 : sub_length)
//             if ((is_sub = mx_strncmp(str, sub, sub_length)) == 0)
//                 ++result;

//         return (int)result;
//     }
//     return str && sub ? 0 : -1;
//}

int get_char_index(const char *str, char c)
{
    if (str == NULL)
        return -2;

    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return i;

    return -1;
}

int get_substr_index(const char *str, const char *sub)
{

    if (!str || !sub)
        return -2;

    char *res = mx_strstr(str, sub);
    if (res)
        return res - str;

    return -1;
}

int check_substr(const char *src, const char *sub)
{
    if (!src)
        return 0;

    if (!sub)
        return -1;

    int result = 0;

    for (int i = 0; sub[i]; i++)
    {
        if (src[i] != sub[i])
            return (src[i] - sub[i]);
    }

    return result;
}
