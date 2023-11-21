#include "sort.h"
/**
 *get_max - Function to get the maximum value in an array
 *This function finds and returns the maximum value in an array.
 * Parameters:
 *@array: a pointer to the array
 *@size: the number of elements in the array
 * Return: The maximum integer value found in the array.
 */
int get_max(int *array, int size)
{
	int max, i;
	int current_element;

	for (max = array[0], i = 1; i < size; i++)
	{
		current_element = array[i];
		if (current_element > max)
			max = current_element;
	}

	return (max);
}
/**
 * counting_sort - Function to sort an array using the Counting Sort algorithm
 * Description: This function sorts an array using the Counting Sort algorithm.
 * Parameters:
 *@array: a pointer to the array
 *@size: the number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;
	int count_size, sorted_size;

	if (array == NULL || size < 2)
		return;

	sorted_size = sizeof(int) * size;
	sorted = malloc(sorted_size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count_size = sizeof(int) * (max + 1);
	count = malloc(count_size);
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}


