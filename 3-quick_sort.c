#include "sort.h"

/**
 * partition - partitions an array
 * @array: array to be partitioned
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (array[j] < pivot && i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - sorts an array
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: nothing
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low >= high || low < 0)
		return;
	p = partition(array, low, high, size);
	quick_sort_recursive(array, low, p - 1, size);
	quick_sort_recursive(array, p + 1, high, size);
}

/**
 * quick_sort - sorts an array
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}
