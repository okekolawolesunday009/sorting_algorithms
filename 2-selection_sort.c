#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array  of integers using quick sort
 *
 * @array: The array to be printed
 * @size: The array to be printed
 */

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *array, size_t size)
{
    size_t i, j, min, temp;

    for (i = 0; i < size; i++)
    {
	    min = 1;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
                min = j;

        }

        if (min != i)
        {
            swap(&array[i], &array[min]);
            print_array(array, size);
        }


    }

}
