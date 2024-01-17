#include "sort.h"

/**
 * modified_selection_sort - function that sorts an array of integers
 * in ascending order using modified selection sort algorithm
 *
 * @array: The array of integers to be sorted
 * @size: the number of elements in the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		tmp = i;
		flag = 0;
		for (index = i + 1; index < size; index++)
		{
			if (array[tmp] > array[index])
			{
				tmp = index;
				flag += 1;
			}
		}
		if (i != tmp)
		{
			swap = array[i];
			array[i] = array[tmp];
			array[tmp] = swap;
			print_array(array, size);
		}
	}
}
