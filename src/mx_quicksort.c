#include "libmx.h"

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {

            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int mx_quicksort(int *arr, int left, int right)
{
    int swaps = 0;
    if (left < right)
    {

        int pi = partition(arr, left, right);
        swaps++;

        mx_quicksort(arr, left, pi - 1);
        mx_quicksort(arr, pi + 1, right);
    }
    return swaps;
}
