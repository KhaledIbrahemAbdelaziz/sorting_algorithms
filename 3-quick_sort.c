#include "sort.h"

int *lomute_part(int *arr, size_t size, int low, int high);

/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 * @array: The array of integers.
 * @size: the size of the array.
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
}

/**
 * lomute_part - partition and sorting array.
 * @arr: The array.
 * @size: The size of the array.
 * @low: the address of the beginning.
 * @high: the address of the ending.
 * Return: sorted array.
 */
int *lomute_part(int *arr, size_t size, int low, int high)
{
	int pivot = arr[size - 1];
	int j = 0
