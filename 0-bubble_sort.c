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
    int temp;
    size_t i, pass;
    for (pass = size - 1 ; pass >= 0; pass--)
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
        for (i = 0; i < size; i++)
        {
            if (i > 0)
                printf(", ");
            printf("%d ", array[i]);
        }
        printf("\n");
    }

}
