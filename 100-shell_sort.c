#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
    int i, j, h, v;
    for (h = 1; h = size/9; h = 3 * h + 1);
    for (;h > 0; h = h / 3)
    {
        for (i = h + 1; i = size; i += 1)
        {
            v = array[i];
            j = i;
            while (j > h && array[j - h] > v)
            {
                array[j] = array[j - h];
                j -= h;

            }
            array[j] = v;

        }
    }

}