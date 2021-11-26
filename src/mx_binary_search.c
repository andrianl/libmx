#include <stdio.h>

int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        (*count)++;

        if (mx_strcmp(arr[mid], s) == 0)
            return mid;

        else if (mx_strcmp(arr[mid], s) < 0)
            start = mid + 1;

        else
            end = mid - 1;
        mid = (start + end) / 2;
    }
    *count = 0;
    return -1;
}

// int main()
// {
//     char *arr[] = {"222", "Abcd", "aBc", "ab", "az", "z"};
//     int count = 0;
//     printf("%d\n", mx_binary_search(arr, 6, "ab", &count));
//     printf("%d\n", count);
//     count = 0;
//     printf("%d\n", mx_binary_search(arr, 6, "aBc", &count));
//     printf("%d\n", count);
// }
