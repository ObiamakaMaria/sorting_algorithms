#include "sort.h"

void custom_swap(listint_t **head, listint_t *node1, listint_t *node2);
/**
 * insertion_sort_list - This function sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 *
 * @list: A pointer to the head of the doubly linked list.
 *
 * Return : Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pt1, *pt2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (pt1 = (*list)->next; pt1 && pt1->prev; pt1 = pt1->next)
	{
		for (; pt1 && pt1->prev && pt1->n < pt1->prev->n;
				pt1 = pt1->prev)
		{
			pt2 = pt1->prev;
			custom_swap(list, pt2, pt1);
			print_list(*list);
			pt1 = pt1->next;
		}
	}
}

/**
 * custom_swap - This function swaps two nodes in a doubly
 * linked list.
 *
 * @head: A pointer to the head of the list.
 * @node1: The first node to swap.
 * @node2: The second node to swap.
 *
 * Return: Void
 */
void custom_swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;

	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}
