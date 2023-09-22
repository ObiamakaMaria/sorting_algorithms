#include "sort.h"

/**
 * bubble_sort - This function sorts an array of integers
 * in ascending orderusing Bubble Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	int temp;
	size_t i;

	if (size < 2 || array == NULL)
		return;

	do {
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				/* Swap elements and set swapped to 1 */
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				swapped = 1;

				/* Print the array after the swap */
				print_array(array, size);
			}
		}
	} while (swapped);
}
