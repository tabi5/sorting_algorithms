#ifndef SORT_H
#define SORT_H
/* Define SORT_H */

#include <stdio.h>
/* Include standard input/output library */
#include <stdlib.h>
 /* Include standard library */

/* Macros defining the direction of comparison for bitonic sort */
#define UP 0  /* Define UP as 0 */
#define DOWN 1  /* Define DOWN as 1 */

/**
 * enum bool - Defines Boolean values.
 * @false: Represents a false condition, equivalent to 0.
 * @true: Represents a true condition, equivalent to 1.
 */
 /* Define a new data type named 'bool' */
typedef enum bool
{
	false = 0,  /* false is equivalent to 0 */
	true  /* true is equivalent to 1 */
} bool;

/**
 * struct listint_s - Defines a node in a doubly linked list.
 *
 * @n: The integer value stored in the node.
 * @prev: A pointer to the previous node in the list.
 * @next: A pointer to the next node in the list.
 */
typedef struct listint_s
{
	const int n;
	/* The integer value stored in the node */
	struct listint_s *prev;
	/* A pointer to the previous node in the list */
	struct listint_s *next;
	/* A pointer to the next node in the list */
} listint_t;

/* Functions to print arrays and linked lists */
void print_array(const int *array, size_t size);
/* Function to print an array */
void print_list(const listint_t *list);
/* Function to print a linked list */

/* Functions implementing various sorting algorithms */
void bubble_sort(int *array, size_t size);
 /* Function to sort an array using bubble sort */
void insertion_sort_list(listint_t **list);
 /* Function to sort a linked list using insertion sort */
void selection_sort(int *array, size_t size);
 /* Function to sort an array using selection sort */
void quick_sort(int *array, size_t size);
 /* Function to sort an array using quick sort */
void shell_sort(int *array, size_t size);
 /* Function to sort an array using shell sort */
void cocktail_sort_list(listint_t **list);
 /* Function to sort a linked list using cocktail sort */
void counting_sort(int *array, size_t size);
 /* Function to sort an array using counting sort */
void merge_sort(int *array, size_t size);
 /* Function to sort an array using merge sort */
void heap_sort(int *array, size_t size);
/* Function to sort an array using heap sort */
void radix_sort(int *array, size_t size);
/* Function to sort an array using radix sort */
void bitonic_sort(int *array, size_t size);
/* Function to sort an array using bitonic sort */
void quick_sort_hoare(int *array, size_t size);
  /* Function to sort an array using Hoare's quick sort */

#endif /* SORT_H */


