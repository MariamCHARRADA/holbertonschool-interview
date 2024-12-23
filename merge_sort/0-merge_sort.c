#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays into sorted order.
 * @array: The array to sort.
 * @start: Starting index of the section.
 * @mid: Middle index of the section.
 * @end: Ending index of the section.
 * @copy: Copy of the array used for merging.
 */
void merge(int *array, int start, int mid, int end, int *copy)
{
    int left = start;
    int right = mid;
    int i;

    for (i = start; i < end; i++)
    {
        if (left < mid && (right >= end || copy[left] <= copy[right]))
        {
            array[i] = copy[left];
            left++;
        }
        else
        {
            array[i] = copy[right];
            right++;
        }
    }
}

/**
 * split - Recursively splits the array and merges sorted subarrays.
 * @array: The array to sort.
 * @start: Starting index of the section.
 * @end: Ending index of the section.
 * @copy: Copy of the array used for sorting.
 */
void split(int *array, int start, int end, int *copy)
{
    int mid = (start + end) / 2;
    int i;

    if (end - start <= 1)
        return;

    split(copy, start, mid, array);
    split(copy, mid, end, array);

    printf("Merging...\n");

    printf("[left]: ");
    for (i = start; i < mid; i++)
    {
        printf("%d", copy[i]);
        if (i < mid - 1)
            printf(", ");
    }
    printf("\n[right]: ");
    for (i = mid; i < end; i++)
    {
        printf("%d", copy[i]);
        if (i < end - 1)
            printf(", ");
    }

    merge(array, start, mid, end, copy);

    printf("\n[Done]: ");
    for (i = start; i < end; i++)
    {
        printf("%d", array[i]);
        if (i < end - 1)
            printf(", ");
    }
    printf("\n");
}

/**
 * merge_sort - Sorts an array of integers using the Merge Sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    int *copy;
    size_t i;

    if (!array || size < 2)
        return;

    copy = malloc(sizeof(int) * size);
    if (!copy)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return;
    }

    for (i = 0; i < size; i++)
        copy[i] = array[i];

    split(array, 0, size, copy);
    free(copy);
}
