#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	if (a != b)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}
/**
 * bubble_sort - Sort an array of
 * integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * Return: void
 *
 * Description: This function takes
 * an array of integers and its size as input,
 * and sorts the array in ascending order
 * using the bubble sort algorithm.
 * It prints the array after each swap.
 * If the array is NULL or the size is less than 2,
 * it does nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;
	int *vararray = array;

	if (vararray == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (vararray[j] > vararray[j + 1])
			{
				swap_ints(&vararray[j], &vararray[j + 1]);
				print_array(vararray, size);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

