#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;
	int *element;
	const int *vararray = array;

	i = 0;
	while (vararray && i < size)
	{
		element = (int *)&vararray[i];
		if (i > 0)
			printf(", ");
		printf("%d", *element);
		++i;
	}
	printf("\n");
}

