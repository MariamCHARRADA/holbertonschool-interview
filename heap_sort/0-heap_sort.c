#include "sort.h"

/**
 * sift_down - Sorts an array of integers in ascending order by restoring the
 * heap property
 * @array: The array to be sorted
 * @size: The size of the array
 * @root: The index of the root of the heap
 * @end: The boundary (end) of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t largest = root;
	size_t left	   = 2 * root + 1;
	size_t right   = 2 * root + 2;

	if (left < end && array[left] > array[largest])
		largest = left;
	if (right < end && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		int tmp		   = array[root];

		array[root]	   = array[largest];
		array[largest] = tmp;
		print_array(array, size);
		sift_down(array, size, largest, end);
	}
}

/**
 * heap_sort - Sorts an array using the heap sort
 * algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		int tmp	 = array[0];

		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);

		sift_down(array, size, 0, i);
	}
}
