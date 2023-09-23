#include "sort.h"
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int lomuto_partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[high]);

    return (i);
}

void quick_sort(int *array, size_t size) {
    if (size <= 1)
        return;

    int low = 0;
    int high = size - 1;
    int pivot;

     while (low < high) {
        pivot = lomuto_partition(array, low, high);
        if (pivot - low < high - pivot) {
            quick_sort(array, pivot);
            low = pivot + 1;
        } else {
            quick_sort(array + pivot + 1, high - pivot);
            high = pivot - 1;
        }
        print_array(array, size);
    }
}
