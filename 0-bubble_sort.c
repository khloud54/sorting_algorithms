#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @size: the number of elements in array
 * @array: the array of integers to be sorted
*/
void bubble_sort(int *array, size_t size)
{
	size_t idx, len;
	int temp;
	bool has_swapped = true;

	if (!array || size < 2)
		return;

	len = size;
	while (has_swapped)
	{
		has_swapped = false;
		for (idx = 1; idx < len; idx++)
		{
			if (array[idx - 1] > array[idx])
			{
				temp = array[idx - 1];
				array[idx - 1] = array[idx];
				array[idx] = temp;
				has_swapped = true;
				print_array(array, size);
			}
		}
		len--;

	}
}
