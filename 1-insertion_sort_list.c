#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a listint_t
 * doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 *
 * Return: void
 *
 * Description: This function takes two
 * nodes of a doubly-linked list
 * and swaps their positions in the list.
 * It does not return any value.
 * The function modifies the list in-place.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	listint_t *tmp_next, *tmp_prev;

	tmp_next = n2->next;
	tmp_prev = (*n1)->prev;

	if (tmp_next != NULL)
		tmp_next->prev = *n1;
	n2->prev = tmp_prev;
	n2->next = *n1;
	if (tmp_prev != NULL)
		tmp_prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	(*n1)->next = tmp_next;
	*n1 = tmp_prev;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Return: void
 *
 * Description: This function takes a doubly-linked list of integers
 * and sorts it in ascending order using the insertion sort algorithm.
 * It prints the list after each swap. If the list is NULL or
 * contains less than 2 nodes,
 * it does nothing. The function modifies the list
 * in-place and does not return any value.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *previous_node, *next_node;
	int sorted = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (!sorted)
	{
		sorted = 1;
		for (current_node = (*list)->next; current_node != NULL;
				current_node = next_node)
		{
			next_node = current_node->next;
			previous_node = current_node->prev;

			if (previous_node != NULL && current_node->n < previous_node->n)
			{
				swap_nodes(list, &previous_node, current_node);
				print_list((const listint_t *)*list);
				sorted = 0;
			}
		}
	}
}


