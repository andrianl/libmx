//#include <stdio.h>

int mx_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == '\0')
			return (0);
	return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}


// int main()
// {
//     printf("%d\n", mx_strcmp("Hello", "Good bye"));
//     return 0;    
// }
