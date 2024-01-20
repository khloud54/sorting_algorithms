#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the counting sort algorithm
 *
 * @array: pointer to array
 * @size: size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	int max, *count_array;
	size_t i, j = 0;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count_array = calloc((max + 1), sizeof(int));
	if (!count_array)
		return;

	for (i = 0; i <= max; i++)
	{
		while (count_array[i] > 0)
		{
			array[j++]--;
		}
		print_array(array, size);
	}

	free(count_array);
}
