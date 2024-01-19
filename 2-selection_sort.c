#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min = 0;
	int tmp;

	if (!array || size < 2)
		return;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
