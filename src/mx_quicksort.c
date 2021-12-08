#include "libmx.h"

static void swap_q(int *x, int *y, int *count)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
	++(*count);
}

int mx_quicksort(int *arr, int left, int right)
{
	if (!arr)
		return -1;

	int swaps = 0;
	int i = left, j = right;
	int pivot = arr[left + ((right - left + 1) / 2)];

	while (i <= j)
	{
		while (arr[i] < pivot)
			++i;
		while (arr[j] > pivot)
			--j;

		if (i > j)
			continue;

		if (i < j)
			swap_q(&arr[i], &arr[j], &swaps);

		++i;
		--j;
	}

	i < right ? swaps += mx_quicksort(arr, i, right) : i;
	j > left ? swaps += mx_quicksort(arr, left, j) : j;

	return swaps;
}
