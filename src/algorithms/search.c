#include "algorithms.h"
#include "str.h"

int BinarySearchString(char **arr, unsigned size, const char *s)
{
    unsigned start = 0;
    unsigned end = size - 1;
    unsigned mid = (start + end) / 2;

    while (start <= end)
    {

        if (mx_strcmp(arr[mid], s) == 0)
            return mid;

        else if (mx_strcmp(arr[mid], s) < 0)
            start = mid + 1;

        else
            end = mid - 1;
        mid = (start + end) / 2;
    }

    return -1;
}

int BinarySearch(int *arr, unsigned size, int x)
{
    unsigned start = 0;
    unsigned end = size - 1;
    unsigned mid = (start + end) / 2;

    while (start < end)
    {
        if (arr[mid] == x)
            return mid;

        // if (arr[mid] < x)
        //     start = mid + 1;

        // if (arr[mid] > x)
        //     end = mid - 1;

        start = (arr[mid] < x) * (mid + 1);
        end = (arr[mid] > x) * (mid - 1);

        mid = (start + end) / 2;
    }

    return -1;
}
