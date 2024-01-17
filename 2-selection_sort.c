#include "sort.h"

/**
 * modified_swap_ints - swap two integers in an array using a different approach
 * @a: the first integer to swap
 * @b: the second integer to swap
*/
void modified_swap_ints(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

/**
 * selection_sort -  function that sorts an array of integers in ascending order
 * @array: An array of integers
 * @size: the size of the array
 * Description: prints the array after each swap.
*/
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			*min = *min + array[i];
			array[i] = *min - array[i];
			*min = *min - array[i];

			print_array(array, size);
		}
	}
}
