#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - function that sorts an array of integers
 * in ascending order
 * using the Counting sort algorithm
 * @array: An array to be sorted
 * @size: The size of the array
*/
void counting_sort(int *array, size_t size)
{
	int *counting_arr, max_val;
	size_t i, j, arr_size;

	if (!array || size < 2)
		return;

	max_val = array[0];
	for (i = 0; array[i]; i++)
		if (array[i] > max_val)
			max_val = array[i];

	arr_size = max_val + 1;
	counting_arr = malloc(arr_size * sizeof(int));
	if (!counting_arr)
		return;

	for (i = 0; i < arr_size; i++)
		counting_arr[i] = 0;

	for (i = 0; i < size; i++)
		counting_arr[array[i]] += 1;

	for (i = 1; i < arr_size; i++)
		counting_arr[i] += counting_arr[i - 1];

	print_array(counting_arr, arr_size);

	for (i = 1, j = 0; i < arr_size; i++)
		if (counting_arr[i] != counting_arr[i - 1])
			for (int k = 0, rep = counting_arr[i] - counting_arr[i - 1];
				k < rep; k++)
				array[j++] = i;

	free(counting_arr);
}
