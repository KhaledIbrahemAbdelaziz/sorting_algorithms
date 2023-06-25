#include "sort.h"
#include <stdbool.h>
/* header */

void swap_nodes(listint_t *node_one, listint_t *node_two);

/**
 * cocktail_sort_list - a function that sorts a doubly linked list of
 * integers in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: double pointer to the list
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL;
	listint_t *current;
	bool swapped = true;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while(swapped)
	{
		swapped = false;

		/* forward pass (left to right) */
		current = start;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				/* swap function */
				swap_nodes(current, current->next);
				swapped = true;
			}
			current = current->next;
		}
		if (!swapped)
			break;

		end = current;
		current = end;
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current);
				swapped = true;
			}
			current = current->prev;
		}
		print_list(*list);
		start = current;
	}
}

/**
 * swap_nodes - swap two nodes
 *
 * @node_one: node to be swapped
 *
 * @node_two: node to be swapped
 *
 * Return: void
 */

void swap_nodes(listint_t *node_one, listint_t *node_two)
{
	listint_t *temp_next, *temp_prev;

	if (node_one == node_two)
		return;

	temp_next = node_one->next;
	node_one->next = node_two->next;
	node_two->next = temp_next;

	if (node_one->next != NULL)
		node_one->next->prev = node_one;

	if (node_two->next != NULL)
		node_two->next->prev = node_two;

	/* Update previous pointers */
	temp_prev = node_one->prev;
	node_one->prev = node_two->prev;
	node_two->prev = temp_prev;

	if (node_one->prev != NULL)
		node_one->prev->next = node_one;

	if (node_two->prev != NULL)
		node_two->prev->next = node_two;
}
