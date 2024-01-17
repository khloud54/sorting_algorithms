#include "sort.h"

/**
 * swap - interchange the posotions of two elements in an array
 * @array: array
 * @item1: index of the 1st array element
 * @item2: index of the 2nd array element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int temporary;

	temporary = array[item1];
	array[item1] = array[item2];
	array[item2] = temporary;
}

/**
 * lomuto_partition - partitions the array
 * @array: the integer array to sort
 * @size: the size of the array
 * @start: The index of starting element
 * @end: The index of ending element
 * Return: The position of the last element in its sorted order
*/
int lomuto_partition(int *array, ssize_t start, ssize_t end, size_t size)
{
	int pivot_value = array[end];
	ssize_t current_index = start, finder_index;

	for (finder_index = start; finder_index < end; finder_index++)
	{
		if (array[finder_index] < pivot_value)
		{
			if (array[current_index] != array[finder_index])
			{
				swap(array, current_index, finder_index);
				print_array(array, size);
			}
			current_index++;
		}
	}
	if (array[current_index] != array[end])
	{
		swap(array, current_index, end);
		print_array(array, size);
	}
	return (current_index);
}

/**
 * quicksort_recursive - Implementation of the Quicksort alogorithim
 * @array: the integer array to sort
 * @size: the size of the array
 * @begin: The index of the beginning element in the array
 * @finish: The index of the finishing element in the array
*/ 
void quicksort_recursive(int *array, ssize_t begin, ssize_t finish, int size)
{
	ssize_t position = 0;

	if (begin < finish)
	{
		position = lomuto_partition(array, begin, finish, size);

		quicksort_recursive(array, begin, position -1, size);
		quicksort_recursive(array, position +1, finish, size);
	}
}

/**
 * quick_sort - prepare the terrain for the Quicksort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

