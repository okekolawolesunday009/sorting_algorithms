#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * bubble_sort - sorts an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    size_t i, range;

    int index = 0;
    int max = array[0];
    int min = array[0];
    int *count;


    for (i = 1; 1 < size; i++)
    {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            max = array[i];

    }

    range = max - min + 1;
    count = (int *)malloc(range * sizeof(int));

    if (count == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    for (i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (i = 0; i < size; i++) {
        count[array[i] - min]++;
    }

    int index = 0;
    for (i = 0; i < range; i++) {
        while (count[i] > 0) {
            array[index] = i + min;
            index++;
            count[i]--;
        }
    }

    free(count);

}
