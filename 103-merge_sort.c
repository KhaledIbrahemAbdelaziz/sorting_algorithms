#include "sort.h"
/* header */

void merger(int array[], int *temp, int left_start, int right_end);
void top_down_merge(int array[], int temp[], int left_start, int middle, int right_end);
/**
 * merge_sort - a function that sorts an array of integers in ascending
 * order using the Merge sort algorithm
 *
 * @array: (int) array to sort
 *
 * @size: (int) size of array
 *
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	/* allocate enough memory */
	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	merger(array, temp, 0, size - 1);
	free(temp);
}

void merger(int array[], int *temp, int left_start, int right_end)
{
	int middle;

	/* extra error check */
	if (left_start >= right_end)
		return;

	if (left_start < right_end)
	{
		middle = (left_start + right_end) / 2;

		/* first sub array */
		merger(array, temp, left_start, middle);

		/* second sub array */
		merger(array, temp, middle + 1, right_end);

		top_down_merge(array, temp, left_start, middle, right_end);
	}
}


void top_down_merge(int array[], int temp[], int left_start, int middle, int right_end)
{
	int left_end = middle;
	int right_start = middle + 1;
	int size = right_end - left_start + 1;

	int left = left_start;
	int right = right_start;
	int index = left_start;
	int i;

	while (left <= left_end && right <= right_end)
	{
		if (array[left] <= array[right])
		{
			temp[index] = array[left];
			left++;
		}
		else
		{
			temp[index] = array[right];
			right++;
		}
		index++;
	}

	while (left <= left_end)
	{
		temp[index] = array[left];
		left++;
		index++;
	}
	while (right <= right_end)
	{
		temp[index] = array[right];
		right++;
		index++;
	}

	for (i = left_start; i <= right_end; i++)
	{
		array[i] = temp[i];

		print_array(array, size);
	}
}

