#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers
 * in ascending order using the Shell sort algorithm
 *
 * @size: the array size
 * @array: The array to be sorted
 *
 * Return: Void.
*/
void shell_sort(int *array, size_t size)
{
	int gap = 1, curr, comp, temp;

	while (gap < (int)size)
		gap = 3 * gap + 1;

	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (curr = gap; curr < (int)size; curr++)
		{
			temp = array[curr];

			for (comp = curr; comp >= gap && array[comp - gap] > temp; comp -= gap)
			{
				array[comp] = array[comp - gap];
			}
			array[comp] = temp;
		}
		/* Display array state after each gap iteration */
		print_array(array, size);
	}
}
