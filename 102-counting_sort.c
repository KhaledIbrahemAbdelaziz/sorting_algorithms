#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: the array.
 * @size: the size of it.
 * Return: nothing.
 */
void counting_sort(int *array, size_t size)
{
	int *sorted = NULL, *counts = NULL;
	int j = 0, max = 0;
	size_t i = 0;

	if (array == NULL || size < 2)
		return;
	sorted = malloc(sizeof(int) * size);
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		return;
	}
	for (; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	counts = malloc(sizeof(int) * (max + 1));
	if (counts == NULL)
	{
		free(sorted);
		return;
	}
	for (; j <= max; j++)
		counts[j] = 0;
	for (; i < size; i++)
		counts[array[i]]++;
	for (; j <= max; j++)
		counts[j] = counts[j] + counts[j - 1];
	print_array(counts, max +1);
	for (; i < size; i++)
	{
		sorted[--counts[array[i]]] = array[i];
		counts[array[i]]--;
	}
	free(sorted);
	free(counts);
}
