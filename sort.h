#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* basic function prototypes */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);


/* function prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

/* lomuto functions */
void lomuto_swap(int array[], int a, int b);
int lomuto_partition(int array[], int first, int end);
void lomuto_sort(int array[], int first, int end);

/* merge sort functions */
void merger(int array[], int *temp, int left_start, int right_end);

void top_down_merge(int array[], int temp[], int left_start,
		int middle, int right_end);

void print_extra_implementations(int array[], int temp[], int left_start,
		int middle, int right_start, int right_end);


#endif /* SORT_H */
