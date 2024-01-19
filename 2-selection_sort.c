#include "sort.h"

/**
 * swap_integers - swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
*/
void swap_ints(int *first, int *second)
{
	int temporary;

	temporary = *first;
	*first = *second;
	*second = temporary;
}

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
*/
void selection_sort(int *array, size_t size)
{
	int *current_min;
	size_t idx1, idx2;

	if (array == NULL || size < 2)
		return;

	for (idx1 = 0; idx1 < size - 1; idx1++)
	{
		current_min = array + idx1;

		for (idx2 = idx1 + 1; idx2 < size; idx2++)
			current_min = (array[idx2] < *current_min) ? (array + idx2) : current_min;

		if ((array + idx1) != current_min);
		{
			swap_ints(array + idx1, current_min);
			print_array(array, size);
		}
	}
}
