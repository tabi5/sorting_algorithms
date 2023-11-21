#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);
/**
 * merge_subarr - Merges two sorted subarrays into a single sorted subarray.
 *
 * @subarr: The pointer to the unsorted subarray to be merged
 * @buff: The pointer to the temporary buffer used for merging
 * @front: The index of the first element in the left subarray
 * @mid: The index of the first element in the right subarray
 * @back: The index of the element after the
 * last element in the merged subarray
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t u, j, d = 0;
	int left_element, right_element;
	int varz = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (u = front, j = mid; u < mid && j < back; d++)
	{
		left_element = subarr[u];
		right_element = subarr[j];
		buff[d] = (left_element < right_element) ? left_element : right_element;
		if (left_element < right_element)
			u++;
		else
			j++;
	}
	for (; u < mid; u++)
	{
		left_element = subarr[u];
		buff[d++] = left_element;
	}
	for (; j < back; j++)
	{
		right_element = subarr[j];
		buff[d++] = right_element;
	}
	for (u = front, d = varz; u < back; u++)
		subarr[u] = buff[d++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}
/**
 * merge_sort_recursive - Recursively sorts an unsorted
 * subarray using the merge sort algorithm.
 *
 * @subarr: The pointer to the unsorted subarray to be sorted
 * @buff: The pointer to the temporary buffer used for merging
 * @front: The index of the first element in the subarray
 * @back: The index of the element after the last element in the subarray
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;
	size_t subarr_size = back - front;

	if (subarr_size > 1)
	{
		mid = front + subarr_size / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}
/**
 * merge_sort - Sorts an unsorted array using the merge sort algorithm.
 *
 * @array: The pointer to the unsorted array to be sorted
 * @size: The size of the unsorted array
 */
void merge_sort(int *array, size_t size)
{
	int *buff;
	size_t buff_size;

	if (array == NULL || size < 2)
		return;

	buff_size = sizeof(int) * size;
	buff = malloc(buff_size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}


