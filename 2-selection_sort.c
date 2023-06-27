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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		size_t min = i;
		size_t j;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
		}
	}
}
