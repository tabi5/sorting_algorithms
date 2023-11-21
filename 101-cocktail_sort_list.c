#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);


/**
 * swap_node_ahead - Function to swap a node
 * with the next node in a doubly linked list
 * Parameters:
 *@list: a double pointer to the head of the list
 *@tail: a double pointer to the end of the list
 *@shaker: a double pointer to the node to be swapped
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;
	listint_t *prev_shaker = (*shaker)->prev;
	listint_t *next_tmp = tmp->next;

	if (prev_shaker != NULL)
		prev_shaker->next = tmp;
	else
		*list = tmp;
	tmp->prev = prev_shaker;
	(*shaker)->next = next_tmp;
	if (next_tmp != NULL)
		next_tmp->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}
/**
 * swap_node_behind - Function to swap a node with
 * the previous node in a doubly linked list
 * Parameters:
 *@list: a double pointer to the head of the list
 *@tail: a double pointer to the end of the list
 *@shaker: a double pointer to the node to be swapped
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;
	listint_t *next_node = (*shaker)->next;
	listint_t *prev_node = tmp->prev;

	if (next_node != NULL)
		next_node->prev = tmp;
	else
		*tail = tmp;
	tmp->next = next_node;
	(*shaker)->prev = prev_node;
	if (prev_node != NULL)
		prev_node->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}
/**
 * cocktail_sort_list - Function to sort a doubly linked
 * list using the Cocktail Shaker Sort algorithm
 * Parameters:
 * @list: a double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker, *next_node, *prev_node;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = next_node)
		{
			next_node = shaker->next;
			if (shaker->n > next_node->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = prev_node)
		{
			prev_node = shaker->prev;
			if (shaker->n < prev_node->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}


