#include "sort.h"
/* header */


/**
 * lomuto_swap - a function that swaps element of array
 *
 * @array: array containing elements to be swapped
 *
 * @a: first element
 *
 * @b: second element
 *
 * Return: void
 */
void lomuto_swap(int array[], int a, int b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}


/**
 * lomuto_partition - an implementation of the lomuto swap
 *
 * @array: (int) array containing integer elements
 *
 * @first: (int) points to first element in the array
 *
 * @end: (int) points to last element in the array
 *
 * Return: first element (i)
 */

int lomuto_partition(int array[], int first, int end)
{
	int pivot, i, j;
	static int size, temp;

	i = first;
	pivot = array[end];

	if (temp == 0)
	{
		size = end + 1;
		temp++;
	}

	for (j = first; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				lomuto_swap(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != end)
	{
		lomuto_swap(array, i, end);
		print_array(array, size);
	}
	return (i);
}


/**
 * lomuto_sort - sorts elements in the array
 *
 * @array: array to be sorted
 *
 * @first: points to first element in the array
 *
 * @end: points to last element in the array
 *
 * Return: void
 */

void lomuto_sort(int array[], int first, int end)
{
	int pi;

	if (first < end)
	{
		pi = lomuto_partition(array, first, end);
		lomuto_sort(array, first, pi - 1);
		lomuto_sort(array, pi + 1, end);
	}
}


/**
 * quick_sort - main entry
 *
 * @array: array containing integer elements
 *
 * @size: size of array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1);
}
