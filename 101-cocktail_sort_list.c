#include "sort.h"

/**
 * swap_nodes - swap two nodes
 * @node1: first node
 * @node2: second node
 * @list: list of nodes
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev;

	prev = node1->prev;
	node1->next = node2->next;
	node2->next = node1;
	node2->prev = prev;
	node1->prev = node2;
	if (prev != NULL)
		prev->next = node2;
	else
		*list = node2;
	if (node1->next != NULL)
		node1->next->prev = node1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list of integers
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int is_sorted = 0;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = *list;
	while (!is_sorted)
	{
		is_sorted = 1;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				is_sorted = 0;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (is_sorted)
			break;
		is_sorted = 1;
		current = current->prev;
		while (current->prev)
		{
			if (current->prev->n > current->n)
			{
				swap_nodes(list, current->prev, current);
				is_sorted = 0;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		if (is_sorted)
			break;
	}
}
