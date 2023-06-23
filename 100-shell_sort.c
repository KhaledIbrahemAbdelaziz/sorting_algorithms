#include "sort.h"
/* header */

/**
 * shell_sort - a  function that sorts an array of integers in
 * ascending order using the Shell sort algorithm, using the knuth sequence
 *
 * @array: (int) array to be sorted
 *
 * @size: (size_t) size of array
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, gap;

	if (array == NULL || size < 2)
		return;

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i += 1)
		{
			temp = array[i];
			for (j = i; j >= gap &&
					array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		print_array(array, size);
	}
}
