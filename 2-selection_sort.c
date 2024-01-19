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
	size_t current_idx, start_idx, min_idx;

	if (!array || size < 2)
		return;

	while (start_idx < size)
	{
		min_idx = start_idx;
		current_idx = start_idx + 1;

		while (current_idx < size)
		{
			if (array[current_idx] < array[min_idx])
				min_idx = current_idx;
			current_idx++;
		}

		if (min_idx != start_idx)
		{
			swap(array, start_idx, min_idx);
			print_array(array, size);
		}


		start_idx++;
	}
}
