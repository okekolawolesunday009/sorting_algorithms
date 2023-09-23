#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void bubble_sort(int *array, size_t size)
{
    int pass, temp;
    int i;
    if ( array == NULL || size < 2)
        return;
    for (pass = size - 1 ; pass != 0; pass--)
    {
        for (i = 0; i < pass; i++ )
        {
            if (array[i] > array[i + 1])
            {
                 temp = array[i];
                 array[i] = array[i + 1];
                 array[i + 1] = temp;
            }
           
               
        }
        print_array(array, size);
    }

}
