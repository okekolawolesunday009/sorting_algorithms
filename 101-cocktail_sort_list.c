#include "sort.h"

/**
 * cocktail_sort_list - sprts a doubly linked list in ascending order
 * using the Cocktail Shaker sort algorithm
 * @list: pointer to the doubly linked list
 *
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left = NULL, *right = NULL, *current = NULL;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		current = *list;

		while (current->next != right)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		right = current;

		while (current->prev != left)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}

		left = current;
	} while (swapped);
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the list
 * @node1: first node to be swapped
 * @node2: second node to be swapped
 *
 * Return: void.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (*list == node1)
		*list = node2;
}
