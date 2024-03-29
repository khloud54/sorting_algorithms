#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @size: the number of elements in array
 * @array: the array of integers to be sorted
*/
void bubble_sort(int *array, size_t size)
{
	 size_t i, j;
	 int temp;

	 if (size < 2)
		 return;

	 for (i = 0; i <  size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
