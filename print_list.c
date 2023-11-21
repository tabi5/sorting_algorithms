#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers and the
 * total count of elements
 *
 * @list: The list to be printed.
 * It's a pointer to the first node of a linked list.
 *
 * This function iterates through a linked list
 * of integers, printing each integer
 * in the order they appear in the list.
 * After printing all the integers, it also
 * prints the total count of elements in the list.
 * This function does not return
 * any value. The purpose of this function is
 * to provide a way to visualize the
 * contents of a linked list of integers
 * and understand its size.
 */
void print_list(const listint_t *list)
{
	int i;
	const listint_t *temp = list;
	int count = 0;

	while (temp)
	{
		count++;
		temp = temp->next;
	}

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}


