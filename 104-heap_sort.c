#include "sort.h"


/**
 * swapper - swaps two elements of an array
 *
 * @a: first element
 *
 * @b: second e;ement
 *
 * Return: void
 */

void swapper(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * heapify - a subtree rooted with node index, also the implementation
 * of the heap sort algorithm
 *
 * @array: array containing elements
 *
 * @size: size of array
 *
 * @index: index in array
 *
 * @size_cp: copies the actual size of the array
 *
 * Return: void
 */

void heapify(int *array, int size, int index, int size_cp)
{
	int max_int = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && array[left] > array[max_int])
		max_int = left;

	if (right < size && array[right] > array[max_int])
		max_int = right;

	if (max_int != index)
	{
		swapper(&array[index], &array[max_int]);
		print_array(array, size_cp);
		heapify(array, size, max_int, size_cp);
	}

}


/**
 * heap_sort - sorts an array of integers
 *
 * in ascending order using the Heap sort algorithm.
 *
 * @array: the array.
 *
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t size_cp = size;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size_cp);

	for (i = size - 1; i >= 0; i--)
	{
		swapper(&array[0], &array[i]);
		if (i > 0)
			print_array(array, size);
		heapify(array, i, 0, size_cp);
	}
}
