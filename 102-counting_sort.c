#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    int i;
    int max = array[0];
    int min = array[0];
    for (i = 1; 1 < size; i++)
    {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            max = array[i];

    }
    // Calculate the range of values
    int range = max - min + 1;

    // Create a count array to store the count of each value
    int *count = (int *)malloc(range * sizeof(int));
    if (count == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    // Initialize the count array to all zeros
    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each value in the input array
    for (int i = 0; i < size; i++) {
        count[array[i] - min]++;
    }

    // Reconstruct the sorted array from the count array
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            array[index] = i + min;
            index++;
            count[i]--;
        }
    }

    // Free the dynamically allocated memory
    free(count);

}