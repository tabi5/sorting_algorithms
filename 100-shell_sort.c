#include "sort.h"

/**
 * swap_ints - Function to interchange the values of two integers.
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
 * shell_sort - Function to sort an array of integers
 * using the Shell sort method.
 * @array: Pointer to the array that needs to be sorted.
 * @size: The number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;
	int *vararray = array;

	if (vararray == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && vararray[j - gap] > vararray[j])
			{
				temp = vararray[j];
				vararray[j] = vararray[j - gap];
				vararray[j - gap] = temp;
				j -= gap;
			}
		}
		print_array(vararray, size);
	}
}

