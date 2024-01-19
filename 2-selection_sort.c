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
 * selection_sort - sort an array of integers in ascending order
 * using the selection of sort algorithm.
 *
 * size: size of array
 * @array: array of integers
 * Description: prints the array after each swap.
*/
void selection_sort(int *array, size_t size)
{
	int *min_ptr;
	size_t idx, inner_idx;

	if (array == NULL || size < 2)
		return;

	for (idx = 0; idx < size - 1; idx++)
	{
		min_ptr = array + idx;
		for (inner_idx = idx + 1; inner_idx < size; inner_idx++)
			min_ptr = (array[inner_idx] < *min_ptr) ? (array + inner_idx) : min_ptr;

		if ((array + idx) != min_ptr)
		{
			int temp = *min_ptr;
			*min_ptr = array[idx];
			array[idx] = temp;

			print_array(array, size);
		}
	}
}
