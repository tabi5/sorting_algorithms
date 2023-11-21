#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
/**
 * swap_ints - a function that swaps the values of two integers.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 *
 * Description: This function swaps the values of two integers. It uses
 *              a different logic to swap the values without
 *              a temporary variable.
 *
 * Return: This function does not return a value.
 * It modifies the input integers in-place.
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
 * hoare_partition - a function that performs the Hoare partition scheme.
 * @array: An array of integers to be partitioned.
 * @size: The size of the array.
 * @left: The starting index for the partition.
 * @right: The ending index for the partition.
 *
 * Description: This function performs the Hoare partition scheme on an array.
 * It uses
 *              a pivot element to partition the array into two halves,
 *              one with elements
 *              less than the pivot and one with elements greater
 *              than the pivot.
 *
 * Return: The final index of the pivot element after
 * the partition.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot;
	int above;
	int below;
	int pivot_index = right;
	int start_index = left - 1;
	int end_index = right + 1;

	pivot = array[pivot_index];
	for (above = start_index, below = end_index; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}
/**
 * hoare_sort - a function that performs Hoare sort on an array.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * @left: The starting index for the sort.
 * @right: The ending index for the sort.
 *
 * Description: This function performs a Hoare sort on an array. It uses
 *              a recursive approach to divide the array into two halves and
 *              sort them in opposite directions, then merge them.
 *
 * Return: This function does not return a value. It modifies
 * the input integers in-place.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;
	int diff = right - left;

	if (diff > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}
/**
 * quick_sort_hoare - a function that performs quick sort on an array
 * using the Hoare partition scheme.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: This function performs a quick sort on an array using
 * the Hoare partition scheme. It uses
 *              a recursive approach to divide the array into two
 *              halves and sort them in opposite directions,
 *              then merge them.
 *
 * Return: This function does not return a value.
 * It modifies the input integers in-place.
 */
void quick_sort_hoare(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, start, end);
}


