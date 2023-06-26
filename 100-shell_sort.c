#include "sort.h"
/**
 * shell_sort -Sorts an array using shell_sort algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int space = 1, i, j;
	int tmp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (space < size / 3)
		space = space * 3 + 1;

	while (space > 0)
	{
		for (i = space; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= space && array[j - space] > tmp)
			{
				array[j] = array[j - space];
				j -= space;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		space /= 3;
	}
}
