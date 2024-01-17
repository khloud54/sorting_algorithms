#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the selection sort algorithim.
 *
 * @array: The array of integers to be sorted
 * @size: the number of elements in the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, min_index, swaps_count;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		swaps_count = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[min_index] > array[j])
			{
				min_index = j;
				swaps_count++;
			}
		}

		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;

		if (swaps_count != 0)
			print_array(array, size);
	}
}
