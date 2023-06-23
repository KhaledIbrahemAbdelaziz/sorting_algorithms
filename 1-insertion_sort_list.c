#include "sort.h"
/* header */

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the insertion sort algorith
 *
 * @list: double pointer to the list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;

			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
				*list = temp;

			else
			{
				temp->prev->next = temp;
			}

			print_list(*list);
		}

		current = current->next;
	}
}
