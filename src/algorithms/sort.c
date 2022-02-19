#include "algorithms.h"
#include "utils.h"

void BubbleSort(int *arr, unsigned size)
{
    for (unsigned i = 0; i < size - 1; i++)

        for (unsigned j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
}

void QuickSort(int *arr, int left, int right)
{

    int i = left, j = right - 1, pivot = arr[right];

    while (i < j)
    {
        while (arr[i] <= pivot && i < right)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            --j;
        }

        if (i > j)
            break;

        swap(&arr[i++], &arr[j--]);
    }

    if (arr[i] > (int)pivot)
        swap(&arr[i], &arr[right]);
    if ((int)j > left)
        QuickSort(arr, left, j);
    if ((int)i + 1 < right)
        QuickSort(arr, i + 1, right);
}
