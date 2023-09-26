#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                     order using Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list;
	listint_t *end = NULL;

	while (swapped)
	{
		swapped = 0;

		/* Forward pass (similar to Bubble Sort) */
		while (start && start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
			start = start->next;
		}

		/* If no elements were swapped, list is sorted */
		if (!swapped)
			break;

		swapped = 0;
		end = start;

		/* Backward pass */
		while (start && start->prev != end)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				print_list(*list);
				swapped = 1;
			}
			start = start->prev;
		}

		end = start;
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Double pointer to the head of the list.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	if (!node2->prev)
		*list = node2;
}

