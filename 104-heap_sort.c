#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
/**
 * swap_ints - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Description: This function takes
 * two pointers to integers as parameters.
 * It swaps the values of the integers
 * pointed to by the parameters.
 * The function does not return a value.
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
 * max_heapify - Converts a binary tree into a max heap.
 * @array: Pointer to the array that represents
 * the binary tree.
 * @size: The size of the array.
 * @base: The size of the heap within the array.
 * @root: The index of the root of the binary
 * tree within the array.
 *
 * Description: This function takes a pointer to
 * an array, the size of the array,
 * the size of the heap within the array,
 * and the index of the root of the binary
 * tree within the array as parameters.
 * It converts the binary tree into a max heap,
 * where the parent node is always larger
 * than or equal to its child nodes.
 * The function does not return a value.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	int *vararray = array;
	size_t left, right, large;
	int temp;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && vararray[left] > vararray[large])
		large = left;
	if (right < base && vararray[right] > vararray[large])
		large = right;

	if (large != root)
	{
		temp = vararray[root];
		vararray[root] = vararray[large];
		vararray[large] = temp;
		print_array(vararray, size);
		max_heapify(vararray, size, base, large);
	}

}
/**
 * heap_sort - Sorts an array of integers in ascending
 * order using the Heap sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function takes a pointer to an array and
 * the size of the array as parameters.
 * It sorts the array in ascending order using the Heap
 * sort algorithm. The function first converts
 * the array into a max heap, where the parent node is
 * always larger than or equal to its child nodes.
 * Then it swaps the root of the heap with the last node,
 * reduces the size of the heap by one, and
 * heapifies the root node. This process is repeated until
 * the heap size is reduced to one.
 * The function does not return a value.
 */
void heap_sort(int *array, size_t size)
{
	int *vararray = array;
	int i, temp;

	if (vararray == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(vararray, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		temp = vararray[0];
		vararray[0] = vararray[i];
		vararray[i] = temp;
		print_array(vararray, size);
		max_heapify(vararray, size, i, 0);
	}

}


