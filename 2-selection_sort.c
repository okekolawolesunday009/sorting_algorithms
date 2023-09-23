#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array  of integers using quick sort
 * 
 * @array: The array to be printed
 * @size: The array to be printed
 */

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
        temp = array[min];
        array[min] = array[i];
        array[i] = temp;
        print_array(array, size);

    }
   
}
