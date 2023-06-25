#include "sort.h"

void swap_elements(int *a, int *b);
int lomute_partition(int arr[], int first, int end);
void sort_quick(int arr[], int first, int end);

/**
 * swap_elements - swaps elements
 *
 * @a: first element
 *
 * @b: second element
 *
 * Return: void
 */

void swap_elements(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}


/**
 * lomute_partition - partition the array using the last element as the pivot
 *
 * @first: first element
 *
 * @end: last element
 *
 * Return: void
 */

int lomute_partition(int arr[], int first, int end)
{
	int pivot = arr[end];
	int i = (first - 1), j;

	for (j = first; j <= end - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_elements(&arr[i], &arr[j]);
		}
	}
	swap_elements(&arr[i + 1], &arr[end]);
	return (i + 1);
}

/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 * @array: The array of integers.
 * @size: the size of the array.
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	sort_quick(array, 0, size - 1);
}


/**
 * sort_lomute - sorting by lomute.
 * @a: the array.
 * @size: the size.
 * @low: the address of the beginning.
 * @high: the address of the ending.
 * Return: nothing.
 */
void sort_quick(int arr[], int first, int end)
{
	int pi;

	if (first < end)
	{
		pi = lomute_partition(arr, first, end);
		print_array(arr, end + 1);
		sort_quick(arr, first, pi - 1);
		sort_quick(arr, pi + 1, end);
	}
}
