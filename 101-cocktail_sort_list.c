#include "sort.h"
#include <stdbool.h>
/* header */

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
	start = *list;
	while (swapped)
	{
		swapped = false;

		/* forward pass (left to right) */
		current = start;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				/* swap function */
				swap_nodes(list, current, current->next);
				swapped = true;
				/**
				 * if (current->prev == NULL)
				 * *list = current;
				 */
				print_list(*list);
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = false;
		end = current;
		current = end;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = true;
				/*if (current->prev == NULL)*/
					/*list = current->prev;*/
				print_list(*list);
			}
			else
				current = current->prev;
		}
		start = current;
	}
}

/**
 * swap_nodes - swap two nodes
 *
 * @list: double pointer to the list
 *
 * @node_one: node to be swapped
 *
 * @node_two: node to be swapped
 *
 * Return: void
 */

void swap_nodes(listint_t **list, listint_t *node_one, listint_t *node_two)
{
	if (*list == NULL || list == NULL)
		return;

	if (node_one == node_two)
		return;

	if (node_one->prev != NULL)
		node_one->prev->next = node_two;

	if (node_two->next != NULL)
		node_two->next->prev = node_one;

	node_one->next = node_two->next;
	node_two->prev = node_one->prev;
	node_one->prev = node_two;
	node_two->next = node_one;

	if (node_one->next != NULL)
		node_one->next->prev = node_one;

	if (node_two->prev != NULL)
		node_two->prev->next = node_two;

	if (node_one->prev == NULL)
		*list = node_one;
	else if (node_two->prev == NULL)
		*list = node_two;
}
