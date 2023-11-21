#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);
/**
 * swap_ints - a function that swaps the values of two integers.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 *
 * Description: This function swaps the values of two integers. It uses
 *              a temporary variable to hold the value of the first integer
 *              during the swap.
 *
 * Return: This function does not return a value. It modifies the
 * input integers in-place.
 */
void swap_ints(int *a, int *b)
{
	if (a != b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}
/**
 * bitonic_merge - a function that performs bitonic merge on an array.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * @start: The starting index for the merge.
 * @seq: The sequence size for the merge.
 * @flow: The direction of the sort (UP or DOWN).
 *
 * Description: This function performs a bitonic merge on an array. It uses
 *              a temporary variable to hold the value of the first integer
 *              during the swap.
 *
 * Return: This function does not return a value. It modifies
 * the input integers in-place.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i;
	size_t jump = seq / 2;
	size_t end = start + jump;

	if (seq > 1)
	{
		for (i = start; i < end; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
					(flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}
/**
 * bitonic_seq - a function that performs bitonic sort on an array.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * @start: The starting index for the sort.
 * @seq: The sequence size for the sort.
 * @flow: The direction of the sort (UP or DOWN).
 *
 * Description: This function performs a bitonic sort on an array. It uses
 *              a recursive approach to divide the array into two halves and
 *              sort them in opposite directions, then merge them.
 *
 * Return: This function does not return a value.
 * It modifies the input integers in-place.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";
	size_t end = start + cut;

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, end, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}


/**
 * bitonic_sort - a function that performs bitonic sort on an array.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: This function performs a bitonic sort on an array. It uses
 *              a recursive approach to divide the array into two halves and
 *              sort them in opposite directions, then merge them.
 *
 * Return: This function does not return a value.
 * It modifies the input integers in-place.
 */
void bitonic_sort(int *array, size_t size)
{
	size_t start = 0;
	char flow = UP;

	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, start, size, flow);
}


