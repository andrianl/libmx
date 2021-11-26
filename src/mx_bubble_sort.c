#include "libmx.h"

// A function to implement bubble sort
int mx_bubble_sort(int *arr, int size)
{
    int i, j;
    int swaps = 0;
    for (i = 0; i < size - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swaps++;
            }
            return swaps;
}

