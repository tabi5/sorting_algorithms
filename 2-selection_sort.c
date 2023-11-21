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
 * selection_sort - A function to sort an array of
 * integers in ascending order using the selection sort algorithm.
 *
 * @array: A pointer to the first element of
 * the array to be sorted.
 * @size: The number of elements in the array.
 *
 * return void This function does
 * not return a value. The array is sorted in-place.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	int *current;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		current = array + i;
		min = current;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
			{
				min = array + j;
			}
		}

		if (current != min)
		{
			swap_ints(current, min);
			print_array(array, size);
		}
	}
}
