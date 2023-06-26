#include "sort.h"
/* header */

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


/**
 * merger - set the middle element of the array
 *
 * @array: array to be sorted
 *
 * @temp: temporary memory
 *
 * @left_start: beginning of the left sub array (first element)
 *
 * @right_end: end of right sub array (last element)
 *
 * Return: void
 */

void merger(int array[], int *temp, int left_start, int right_end)
{
	int middle;

	/* extra error check */
	if (left_start >= right_end)
		return;

	middle = (left_start + right_end) / 2;

	/* first sub array */
	merger(array, temp, left_start, middle);

	/* second sub array */
	merger(array, temp, middle + 1, right_end);

	top_down_merge(array, temp, left_start, middle, right_end);

}


/**
 * print_extra_implementations - prints the merging, left, right nd done
 *
 * @array: array containing elements
 *
 * @temp: temporary memory
 *
 * @left_start: start of left sub array
 *
 * @middle: middle element
 *
 * @right_start: start of right sub array
 *
 * @right_end: end of right sub array
 *
 * Return: void
 */

void print_extra_implementations(int array[], int temp[], int left_start,
		int middle, int right_start, int right_end)
{
	int i;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = left_start; i <= middle; i++)
	{
		printf("%d", array[i]);
		if (i != middle)
			printf(", ");
	}
	printf("\n");

	printf("[right]: ");
	for (i = right_start; i <= right_end; i++)
	{
		printf("%d", array[i]);
		if (i != right_end)
			printf(", ");
	}
	printf("\n");

	printf("[Done]: ");
	for (i = left_start; i <= right_end; i++)
	{
		printf("%d", temp[i]);
			if (i != right_end)
				printf(", ");
	}
	printf("\n");
}


/**
 * top_down_merge - implementation of the top down merge algorithm plus
 * extra checks
 *
 * @array: array to be sorted, contains integer elements
 *
 * @temp: temporary memory
 *
 * @left_start: beginning of the left sub array (first element)
 *
 * @middle: element in the middle of the array after the array has been
 * splited into two parts
 *
 * @right_end: end of the right sub array (last element)
 */

void top_down_merge(int array[], int temp[], int left_start, int middle, int right_end)
{
	int left_end = middle;
	int right_start = middle + 1;
	int size = right_end - left_start + 1;
	int left = left_start, right = right_start;
	int index = left_start, i;

	while (left <= left_end && right <= right_end)
	{
		if (array[left] <= array[right])
		{
			temp[index] = array[left];
			left++;
		}
		else
		{temp[index] = array[right];
			right++;}
		index++;
	}

	while (left <= left_end)
	{temp[index] = array[left];
		left++;
		index++;}
	while (right <= right_end)
	{temp[index] = array[right];
		right++;
		index++;}

	print_extra_implementations(array, temp, left_start, middle,
			right_start, right_end);

	for (i = left_start; i <= right_end; i++)
		array[i] = temp[i];

	(void) size;
}
