#include "libmx.h"

// char *mx_strjoin(char const *s1, char const *s2)
// {
//     char *s3;

//     if (!s1 && !s2)
//         return (NULL);
//     if (!s1)
//         return (mx_strdup(s2));
//     if (!s2)
//         return (mx_strdup(s1));
//     if (!(s3 = mx_strnew(mx_strlen(s1) + mx_strlen(s2))))
//         return (NULL);
//     mx_strcpy(s3, s1);
//     mx_strcat(s3, s2);
//     return (s3);
//     //return (NULL);
// }

char *mx_strjoin(char const *s1, char const *s2)
{
    char *new_str = NULL;

    if (s1 == 0 && s2 == 0)
        return 0;
    if (s1 == 0)
        return mx_strdup(s2);
    if (s2 == 0)
        return mx_strdup(s1);

    new_str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

    new_str = mx_strcat(new_str, s1);
    new_str = mx_strcat(new_str, s2);

    return new_str;
}

/*int main()
{
    char *str1= "this";
    char *str2= "dodge ";
    char *str3= NULL;
    printf("%s\n", mx_strjoin(str2, str1));
    printf("%s\n", mx_strjoin(str1, str3));
    printf("%s\n", mx_strjoin(str3, str3));
}*/
