#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

size_t list_len(listint_t *list);

/* Swapping function */
void swap(int *x, int *y);
void switch_nodes(listint_t **list, listint_t **p);

/*partitioning function */
int partition(int *array, int start, int end);

/* Sorting prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_first(int *array, int start, int end);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

/*Printing functions*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


#endif /*SORT_H*/
