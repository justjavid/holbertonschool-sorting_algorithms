#include "sort.h"

/**
 * selection_sort - selection sorting array
 * @array: array
 * @size: array size
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, temp;
	int tmp;

	for (i = 0; i < size; i++)
	{
		temp = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[temp] > array[j])
			{
				temp = j;
			}
		}
		tmp = array[i];
		array[i] = array[temp];
		array[temp] = tmp;
		print_array(array, size);
	}
}
