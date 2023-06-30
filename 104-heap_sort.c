#include "sort.h"

void heapity(int *arr, size_t size, int i);
void buildtree(int *a, size_t size);

/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap sort algorithm.
 * @array: the array.
 * @size: the size of the array.
 * Return: nothing.
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	buildtree(array, size);
	for (i = ((int)size - 1); i >= 0; i++)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapity(array, i, 0);
	}
}

/**
 * heapity - help to parts left and right.
 * @arr: the array.
 * @size: the size of the array.
 * @i: the position of the element in the array.
 * Return: nothing.
 */
void heapity(int *arr, size_t size, int i)
{
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;
	int max = i;
	int tmp;

	if (left < (int)size && arr[left] > arr[max])
		max = left;
	if (right < (int)size && arr[right] > arr[max])
		max = right;
	if (max != i)
	{
		tmp = arr[i];
		arr[i] = arr[max];
		arr[max] = tmp;
		print_array(arr, size);
		heapity(arr, size, max);
	}
}

/**
 * buildtree - build a tree from array.
 * @a: the array.
 * @size: the size of the array.
 * Return: nothing.
 */
void buildtree(int *a, size_t size)
{
	int i;

	for (i = (((int)size / 2) - 1); i >= 0; i--)
		heapity(a, size, i);
}
