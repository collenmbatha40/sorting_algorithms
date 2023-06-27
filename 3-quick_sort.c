#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int partition(int *array, int start, int end)
{
	int pivot = array[end];
	int i = start - 1;
	int j;
	size_t size = 0;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[end]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_first - deploy quick sort using recursion first
 *
 * @array: array of integers
 * @start: the starting index of the sebset to order.
 * @end: the ending index of the subset to order.
 *
 */

void quick_sort_first(int *array, int start, int end)
{
	if (start < end)
	{
		int pivot = partition(array, start, end);

		quick_sort_first(array, start, pivot - 1);
		quick_sort_first(array, pivot + 1, end);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_first(array, 0, size - 1);
}
