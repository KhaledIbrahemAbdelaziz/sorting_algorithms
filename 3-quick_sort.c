#include "sort.h"

int *lomute_part(int *arr, size_t size, size_t low, size_t high);

/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 * @array: The array of integers.
 * @size: the size of the array.
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomute_part(array, size, 0, size - 1);
}

/**
 * lomute_part - partition and sorting array.
 * @arr: The array.
 * @size: The size of the array.
 * @low: the address of the beginning.
 * @high: the address of the ending.
 * Return: sorted array.
 */
int *lomute_part(int *arr, size_t size, size_t low, size_t high)
{
	int pivot = arr[size - 1];
	size_t j = low;
	size_t i;
	size_t tmp1, tmp2;

	for (i = 0; i < size; i++)
	{
		if (arr[i] <= pivot)
		{
			tmp1 = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp1;
			print_array(arr, size);
		}
		j++;
	}
	tmp2 = arr[high];
	arr[high] = arr[j];
	arr[j] = tmp2;
	/*print_array(arr, size);*/
	lomute_part(arr, size, low, j - 1);
	lomute_part(arr, size, j + 1, high);
	return (arr);
}
