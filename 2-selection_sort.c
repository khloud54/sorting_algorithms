#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @size: Number of elements in array
 * @array: The array to be printed
*/
void selection_sort(int *array, size_t size)
{
	size_t idx1 = 0, idx2 = 0, current_min = 0;
	int temporary;

	if (!array || size < 2)
		return;

	while (idx1 < size - 1)
	{
		current_min = idx1;
		idx2 = idx1 + 1;

		while (idx2 < size)
		{
			if (array[idx2] < array[current_min])
				current_min = idx2;
			idx2++;
		}

		if (current_min != idx1)
		{
			temporary = array[idx1];
			array[idx1] = array[current_min];
			array[current_min] = temporary;
			print_array(array, size);
		}

		idx1++;
	}
}
