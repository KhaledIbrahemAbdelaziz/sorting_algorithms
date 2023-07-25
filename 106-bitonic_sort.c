#include "sort.h"

/**
* swapint - swaps index
*
* @l: left index to swap
*
* @r: right index to swap
*/

void swapint(int *l, int *r)
{
	int temp;

	temp = *l;
	*l = *r;
	*r = temp;
}

/**
* b_merge - bitonic merge implementation
*
* @array: array being merged
*
* @low: lowest index
*
* @count: keeps count of slice operation
*
* @dir: direction, asc 1, desc 0
*
* @size: size of array
*/

void b_merge(int *array, int low, int count, int dir, size_t size)
{
	int i, n;

	if (count > 1)
	{
		n = count / 2;
		for (i = low; i < low + n; i++)
		{
			if (((array[i] > array[i + n]) && dir == 1) ||
			(dir == 0 && (array[i] < array[i + n])))
				swapint(&array[i], &array[i + n]);
		}
		b_merge(array, low, n, dir, size);
		b_merge(array, low + n, n, dir, size);
	}
}

/**
* b_sort - bitonic recursive sort implementation, also prints the sorting
* process
*
* @array: array to be sorted
*
* @low: lowest index
*
* @count: keeps count of slice operation
*
* @dir: direction, asc 1, desc 0
*
* @size: size of array for printing
*/

void b_sort(int *array, int low, int count, int dir, size_t size)
{
	int n;

	if (count > 1)
	{
		n = count / 2;
		printf("Merging [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
		b_sort(array, low, n, 1, size);
		b_sort(array, low + n, n, 0, size);
		b_merge(array, low, count, dir, size);
		printf("Result [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
	}
}

/**
* bitonic_sort - bitonic sort implementation
*
* @array: array to be sorted
*
* @size: size of array
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	b_sort(array, 0, size, 1, size);
}
