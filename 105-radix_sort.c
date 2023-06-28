#include "sort.h"
/* header */


/**
 * max_integer - a function that returns the max integr from the array
 *
 * @array: array to iterate
 *
 * @size: size of array
 *
 * Return: max integer
 */

int max_integer(int *array, size_t size)
{
	size_t i;
	int bigg;

	if (array == NULL)
		return (-1);

	bigg = array[0];
	for (i = 0; i < size; i++)
	{
		if (bigg < array[i])
			bigg = array[i];
	}
	return (bigg);
}


/**
 * raidx_sort - a function that sorts an array of integers in ascending
 * order using the Radix sort algorithm
 *
 * @array: array to be sorted, contains integer
 *
 * @size: size of array
 *
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int *output, max, digit_place = 1, count[1024] = {0};
	int n = size, i;

	if (array == NULL || size < 2)
		return;

	max = max_integer(array, size);

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	while (max / digit_place > 0)
	{
		/* resets count array to 0*/
		for (i = 0; i < 10; i++)
			count[i] = 0;

		for (i = 0; i < n; i++)
			count[(array[i] / digit_place) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = n - 1; i >= 0; i--)
		{
			output[count[(array[i] / digit_place) %
				10] - 1] = array[i];
			count[(array[i] / digit_place) % 10]--;
		}

		for (i = 0; i < n; i++)
		{
			array[i] = output[i];
		}
		digit_place *= 10;
		print_array(array, size);
	}
	free(output);
}

