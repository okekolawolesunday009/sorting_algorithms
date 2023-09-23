#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using Insertion sort algorithm
 * @list: the list to be sorted/
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next; /* start from 2nd element */
	while (current)
	{
		next = current->next; /* strore next node */

		/* check if current node is smaller than the previous node */
		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;

			/* swap the nodes */
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;

			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current; /* update head od the */
						 /*   list if needed */
			print_list(*list); /* print the list after each swap */
		}
		current = next;
	}
}
