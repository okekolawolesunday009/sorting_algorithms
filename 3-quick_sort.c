#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - partion scheme for Quick sort
 * @array: the array to be partitioned
 * @low: starting index f the partition
 * @high: ending index of the partition
 * @size: size of the array
 *
 * Return: index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}

/**
 * quicksort - recursive function to perform quick sort
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: szie of the array
 *
 * Return: void.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers ina scending order
 * using Quick sort algorithm with Lomuto partition scheme
 * @array: pointer to the array to be sorted
 * @size: of the array
 *
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
