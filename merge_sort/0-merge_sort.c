#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays into a sorted array.
 * @array: The original array.
 * @left: The left subarray.
 * @right: The right subarray.
 * @size: The size of the original array.
 */
void merge(int *array, int *left, int *right, size_t size)
{
    size_t i = 0, j = 0, k = 0, left_size = size / 2, right_size = size - left_size;

    printf("Merging...\n[left]: ");
    for (i = 0; i < left_size; i++)
        printf("%d%s", left[i], (i < left_size - 1) ? ", " : "");
    printf("\n[right]: ");
    for (i = 0; i < right_size; i++)
        printf("%d%s", right[i], (i < right_size - 1) ? ", " : "");
    printf("\n");

    i = 0;
    while (i < left_size && j < right_size)
        array[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < left_size)
        array[k++] = left[i++];
    while (j < right_size)
        array[k++] = right[j++];

    printf("[Done]: ");
    for (i = 0; i < size; i++)
        printf("%d%s", array[i], (i < size - 1) ? ", " : "");
    printf("\n");
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    size_t mid = size / 2;
    int *left = malloc(mid * sizeof(int));
    int *right = malloc((size - mid) * sizeof(int));

    if (!left || !right)
        return;

    for (size_t i = 0; i < mid; i++)
        left[i] = array[i];
    for (size_t i = mid; i < size; i++)
        right[i - mid] = array[i];

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(array, left, right, size);

    free(left);
    free(right);
}
