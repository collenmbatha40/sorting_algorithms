#include "sort.h"

/**
* merge - Merges the splits from merge_sorty
* @array: Array split to merge
* @start: lowest index of split
* @middle: middle index of split
* @end: high index of split
* @temp: temp array for merging
*/

void merge(int *array, int start, int middle, int end, int *temp)
{
	int i, j, k, l = 0, r = 0, n, left[4096], right[4096];

	printf("Merging...\n");
	i = start, j = middle + 1, k = l = 0;
	while (i <= middle && j <= end)
	{
		if (array[i] <= array[j])
			temp[k] = left[l] = array[i], k++, i++, l++;
		else
			temp[k] = right[r] = array[j], k++, j++, r++;
	}
	while (i <= middle)
		temp[k] = left[l] = array[i], k++, i++, l++;
	while (j <= end)
		temp[k] = right[r] = array[j], k++, j++, r++;
	printf("[left]: ");
	for (n = 0; n < l; n++)
		(n == 0) ? printf("%d", left[n]) : printf(", %d", left[n]);
	printf("\n[right]: ");
	for (n = 0; n < r; n++)
		(n == 0) ? printf("%d", right[n]) : printf(", %d", right[n]);
	printf("\n[Done]: ");
	for (i = start; i <= end; i++)
	{
		array[i] = temp[i - start], printf("%d", array[i]);
		if (i != end)
			printf(", ");
		else
			printf("\n");
	}
}

/**
* merge_sort_first - recurrsive function utilizing merge sort algorithm
* @array: Array
* @start: Lowest index of split
* @end: highest index of split
* @temp: temp array for mergin
*/

void merge_sort_first(int *array, int start, int end, int *temp)
{
	int middle;

	if (start < end)
	{
		middle = ((end + start - 1) / 2);
		merge_sort_first(array, start, middle, temp);
		merge_sort_first(array, middle + 1, end, temp);
		merge(array, start, middle, end, temp);
	}
}

/**
* merge_sort - Sorts array with merge sort algorithm
* @array: array to sort
* @size: Size of array
*/

void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * (size + 1));
	if (temp == NULL)
		return;
	merge_sort_first(array, 0, size - 1, temp);
	free(temp);
}
