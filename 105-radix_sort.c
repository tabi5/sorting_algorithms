#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);
/**
 * get_max - a function that returns the maximum value in an array.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function iterates over an array of integers,
 *              finds the maximum value, and returns it.
 *
 * Return: The maximum value in the array. If the array is empty,
 *         the return value is undefined.
 */
int get_max(int *array, int size)
{
	int max_value;
	int i;
	int start_index = 1;

	max_value = array[0];

	for (i = start_index; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	return (max_value);
}
/**
 * radix_counting_sort - a function that performs
 * radix counting sort on an array.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * @sig: The significant digit to be considered for sorting.
 * @buff: A buffer array for temporary storage during sorting.
 *
 * Description: This function performs radix counting sort on an array.
 * It uses
 *              a buffer for temporary storage and sorts based on
 *              a significant digit.
 *              The function modifies the input array in-place
 *              to sort the elements.
 *
 * Return: This function does not return a value.
 * It sorts the input array in-place.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;
	int index;
	int start_index = 1;
	int end_index = size - 1;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		index = (array[i] / sig) % 10;
		count[index] += 1;
	}

	for (i = start_index; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = end_index; (int)i >= 0; i--)
	{
		index = (array[i] / sig) % 10;
		buff[count[index] - 1] = array[i];
		count[index] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}
/**
 * radix_sort - a function that performs radix sort on an array.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: This function performs radix sort on an array.
 * It uses
 *              a buffer for temporary storage and sorts based on
 *              a significant digit.
 *              The function modifies the input array in-place
 *              to sort the elements.
 *
 * Return: This function does not return a value.
 * It sorts the input array in-place.
 */
void radix_sort(int *array, size_t size)
{
	int max_value;
	int sig;
	int *buff;
	int start_sig = 1;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max_value = get_max(array, size);
	for (sig = start_sig; max_value / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}


