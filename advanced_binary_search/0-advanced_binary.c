#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints an array or subarray
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_binary - Recursive helper function for advanced binary search
 * @array: Pointer to the first element of the array
 * @start: Starting index of the current subarray
 * @end: Ending index of the current subarray
 * @value: Value to search for
 * Return: Index where value is located, or -1 if not found
 */
int recursive_binary(int *array, size_t start, size_t end, int value)
{
	size_t mid;

	if (start > end)
		return (-1);

	print_array(array, start, end);

	mid = start + (end - start) / 2;

	if (array[mid] == value && (mid == start || array[mid - 1] != value))
		return (mid);

	if (array[mid] >= value)
		return (recursive_binary(array, start, mid, value));

	return (recursive_binary(array, mid + 1, end, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *                   and returns the index of the first occurrence
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursive_binary(array, 0, size - 1, value));
}
