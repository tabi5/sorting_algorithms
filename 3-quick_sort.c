#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
/**
 * swap_ints - Swaps the values of two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;
	int *vara = a;
	int *varb = b;

	tmp = *vara;
	*vara = *varb;
	*varb = tmp;
}
/**
 *  lomuto_partition - Partitions the array for quicksort using
 *  the Lomuto partition scheme.
 *
 * @array: Pointer to the first element of the array to be partitioned.
 * @size: The number of elements in the array.
 * @left: The starting index of the section to be partitioned.
 * @right: The ending index of the section to be partitioned.
 * Return: The final index of the pivot after partitioning.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, varabove, varbelow;
	int *vararray = array;
	int varleft = left;
	int varright = right;


	pivot = vararray + varright;
	for (varabove = varbelow = varleft; varbelow < varright; varbelow++)
	{
		if (vararray[varbelow] < *pivot)
		{
			if (varabove < varbelow)
			{
				swap_ints(vararray + varbelow, vararray + varabove);
				print_array(vararray, size);
			}
			varabove++;
		}
	}

	if (vararray[varabove] > *pivot)
	{
		swap_ints(vararray + varabove, pivot);
		print_array(vararray, size);
	}

	return (varabove);
}
/**
 * lomuto_sort - Recursively sorts the sections of the array around the pivot.
 *
 * @array: Pointer to the first element of the array to be sorted.
 * @size: The number of elements in the array.
 * @left: The starting index of the section to be sorted.
 * @right: The ending index of the section to be sorted.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;
	int *vararray = array;
	int varleft = left;
	int varright = right;
	int vardiff = varright - varleft;


	if (vardiff > 0)
	{
		part = lomuto_partition(vararray, size, varleft, varright);
		lomuto_sort(vararray, size, varleft, part - 1);
		lomuto_sort(vararray, size, part + 1, varright);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the quicksort algorithm.
 *
 * @array: Pointer to the first element of the array to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	int *vararray = array;

	if (vararray == NULL || size < 2)
		return;

	lomuto_sort(vararray, size, 0, size - 1);
}

