#include "sort.h"

int lomute_part(int *arr, size_t size, int low, int high);
void sorting_lomute(int *a, size_t size, int low, int high);

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
	sorting_lomute(array, size, 0, size - 1);
}

/**
 * lomute_part - partition and sorting array.
 * @arr: The array.
 * @size: The size of the array.
 * @low: the address of the beginning.
 * @high: the address of the ending.
 * Return: address of pivot.
 */
int lomute_part(int *arr, size_t size, int low, int high)
{
	int pivot = arr[high];
	int j = low;
	int i;
	int tmp1, tmp2;

	for (i = low; i <= high; i++)
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
	print_array(arr, size);
	/**
	 * lomute_part(arr, size, low, j - 1);
	 * lomute_part(arr, size, j + 1, high);
	 */
	return (j);
}

/**
 * sorting_lomute - sorting by lomute.
 * @a: the array.
 * @size: the size.
 * @low: the address of the beginning.
 * @high: the address of the ending.
 * Return: nothing.
 */
void sorting_lomute(int *a, size_t size, int low, int high)
{
	int arrs;

	if (low >= high)
		return;
	arrs = lomute_part(a, size, low, high);
	sorting_lomute(a, size, low, arrs - 1);
	sorting_lomute(a, size, arrs + 1, high);
}
