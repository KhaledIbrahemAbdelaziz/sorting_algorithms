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
	size_t i, j, gap;
	int temp;

	if (array == NULL || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = (gap * 3) + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j > gap - 1 && array[j - gap] >= temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
