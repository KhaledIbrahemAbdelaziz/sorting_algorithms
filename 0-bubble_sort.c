#include "sort.h"
/**
 * bubble_sort - sorts an array of integers
 * in ascending order.
 * @array: The array of integers.
 * @size: The size of the array.
 * Return: nothing to return.
 */
void bubble_sort(int *array, size_t size)
{
	int tmp_arr;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp_arr = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp_arr;
				print_array(array, size);
			}
		}
	}
	printf("\n");
}
