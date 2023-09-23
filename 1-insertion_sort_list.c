#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: The list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *sorted, *updated, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return; 
    sorted = NULL;
    current = *list;

    while (current != NULL)
    {
        updated = current->next;
        
        if (sorted == NULL || current->n < sorted->n)
        {
            current->next = sorted;
            current->prev = NULL;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
           tmp = sorted;

            while (tmp->next != NULL && tmp->next->n < current->n)
            {
                tmp = tmp->next;
            }
            
            current->next = tmp->next;
            if (tmp->next != NULL)
                tmp->next->prev = current;
            tmp->next = current;
            current->prev = tmp;
        }

        current = updated;
        print_list(sorted);
    }

    *list = sorted;
}
