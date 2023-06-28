#include "sort.h"
/* header */
void print_all(int left, int *l_temp, int right, int *r_temp,
		int left_start, int right_end, int *array, int *temp);
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

	middle = ((left_start + right_end - 1) / 2);

	/* first sub array */
	merger(array, temp, left_start, middle);

	/* second sub array */
	merger(array, temp, middle + 1, right_end);

	top_down_merge(array, temp, left_start, middle, right_end);

}

void print_all(int left, int *l_temp, int right, int *r_temp,
		int left_start, int right_end, int *array, int *temp)
{
	int i, j;

	printf("[left]: ");
	for (i = 0; i < left; i++)
	{
		if (i == 0)
			printf("%d", r_temp[i]);
		else
			printf(", %d", r_temp[i]);
	}
	printf("\n[right]: ");
	for (i = 0; i < right; i++)
	{
		if (i == 0)
			printf("%d", l_temp[i]);
		else
			printf(", %d", l_temp[i]);
	}
	printf("\n[Done]: ");
	for (j = left_start; j <= right_end; j++)
	{
		array[j] = temp[j - left_start];
		printf("%d", array[j]);
		if (j != right_end)
			printf(", ");
		else
			printf("\n");
	}
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

void top_down_merge(int *array, int *temp, int left_start,
		int middle, int right_end)
{
	int index, r_start, left = 0, right = 0, key = 0;
	int l_temp[1024], r_temp[1024];

	printf("Merging...\n");
	index = left_start, r_start = middle + 1;
	while (index <= middle && r_start <= right_end)
	{
		if (array[index] <= array[r_start])
		{
			temp[key] = array[index];
			l_temp[left] = array[index];
			key++;
			index++;
			left++;
		}
		else
		{
			temp[key] = array[r_start];
			r_temp[right] = array[r_start];
			key++;
			r_start++;
			right++;
		}
	}

	while (index <= middle)
	{
		temp[key] = array[index];
		l_temp[left] = array[index];
		key++;
		index++;
		left++;
	}
	while (r_start <= right_end)
	{
		temp[key] = array[r_start];
		r_temp[right] = array[r_start];
		key++;
		r_start++;
		right++;
	}
	print_all(left, l_temp, right, r_temp, left_start, right_end,
			array, temp);
}
