#include "sort.h"
/* header */

/**
 * selection_sort - a function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: (int) array to sort
 *
 * @size: (size_t) size of array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, first_element;
	int temp;

	if (size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		first_element = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[first_element])
				first_element = j;
		}

		if (first_element != i)
		{
			temp = array[first_element];
			array[first_element] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
