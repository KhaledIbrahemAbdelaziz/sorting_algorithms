#include "sort.h"

void heapity(int *arr, size_t size, int i);
void swaper(int *a, int *b);


/**
 * swaper - swaps two elements of an array
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
 * heapity - a subtree rooted with node i
 *
 * @array: array containing elements
 *
 * @size: size of array
 *
 * @i: index in array
 *
 * Return: void
 */

void heapity(int *array, size_t size, int i)
{
	int max_int = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if ((left < size) && (array[left] > array[max_int]))
		max_int = left;

	if ((right < size) && (array[right] > array[max_int]))
		max_int = right;

	if (max_int != i)
	{
		swapper(&array[i], &array[max_int]);
		print_array(array, size);
		heapity(array, size, max_int);
	}
}


/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap sort algorithm.
 * @array: the array.
 * @size: the size of the array.
 * Return: nothing.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapity(array, size, i);

	for (i = size - 1; i >= 0; i--)
	{
		swapper(&array[0], &array[i]);
		print_array(array, size);
		heapity(array, i, 0);
	}
}
