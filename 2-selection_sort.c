#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array  of integers using quick sort
 * @array: The array to be printed
 * @size: The array to be printed
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (array == NULL || size < 2) /* ensure more than 2 elements */
		return;
	for (i = 0; i < size - 1; i++) /* iterate through the array */
	{
		min = i; /* assuming current element is the minimum */
		for (j = i + 1; j < size; j++) /* check next item */
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
