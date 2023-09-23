#include "sort.h"
#include <stdio.h>

/**
 * partiton - sorts an array  of integers using quick sort
 * 
 * @a: The array to be printed
 * @b: The array to be printed
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partiton - sorts an array  of integers using quick sort
*
 * @low: The array to be printed
 * @high: The array to be printed
 * @a: Number of elements in @array
 */
int partition (int A[], int low, int high)
{
    int left, right, pivot_item;
    pivot_item = A[low];
    left = low;
    right = high;
    while (left > right)
    {
        while (A[left] <= pivot_item)
            left++;
        while (A[left] >= pivot_item)
            right--;
        if (left < right)
            swap(left, right);
    }
    A[low] = A[right];
    A[right] = pivot_item;
    return (right);


}

/**
 * quick_sort - sorts an array  of integers using quick sort
*
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void quick_sort(int *array, size_t size)
{
    int low, high, pivot;
    low = 0;
    high = size - 1;
    if (size <= 1)
        return;

    if (low < high) {
        pivot = partition(array, low, high);
        quick_sort(array, pivot);
        quick_sort(array + pivot + 1, size - pivot - 1);
    }

}