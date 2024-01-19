#include "sort.h"

/**
 * swap_ints - swap two integers in an array.
 * @x: The first integer to swap
 * @y: The second integer to swap.
*/
void swap_ints(int *x, int *y)
{
	int temporary;

	temporary = *x;
	*x = *y;
	*y = temporary;
}


/**
 * selection_sort - sort list with selection_sort
 *
 * @size: Number of elements in array
 * @array: The array to be printed
*/
void selection_sort(int *array, size_t size);
{
	size_t idx1, idx2, min_idx, tmp;

	if (array == NULL)
		return;

	for (idx1 = 0; idx1 < size; idx1++)
	{
		min_idx = idx1;

		for (idx2 = idx1; idx2 < size; idx2++)
		{
			if (array[idx2] < array[min_idx])
			{
				min_idx = idx2;
			}
		}

		if (min_idx != idx1)
		{
			tmp = array[min_idx];
			array[min_idx] = array[idx1];
			array[idx1] = tmp;

			print_array(array, size);
		}
	}
}
