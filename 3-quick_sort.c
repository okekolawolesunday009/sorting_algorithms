#include "sort.h"
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot_item = array[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        while (left <= right && array[left] <= pivot_item)
            left++;
        while (array[right] >= pivot_item)
            right--;
        if (left <= right)
            swap(&array[left], &array[right]);
    }

    swap(&array[low], &array[right]);
    return right;
}


void quick_sort(int *array, size_t size) {
    if (size <= 1)
        return;

    int low = 0;
    int high = size - 1;
    int pivot;

    while (low < high) {
        pivot = partition(array, low, high);
        if (pivot - low < high - pivot) {
            quick_sort(array, pivot);
            low = pivot + 1;
        } else {
            quick_sort(array + pivot + 1, high - pivot);
            high = pivot - 1;
        }
    }
}
