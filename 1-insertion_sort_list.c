#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *       in ascending order using the Insertion sort algorithm
 * @list: list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = ((*list)->next);
	while (current)
	{
		prev_node = current->prev;
		next_node = current->next;
		while (prev_node && prev_node->n > current->n)
		{
			current->next = prev_node;
			current->prev = prev_node->prev;
			prev_node->prev = current;
			prev_node->next = next_node;
			if (current->prev != NULL)
				current->prev->next = current;
			if (next_node != NULL)
				next_node->prev = prev_node;
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
			prev_node = current->prev;
			next_node = current->next;
		}
		current = next_node;
	}
}
