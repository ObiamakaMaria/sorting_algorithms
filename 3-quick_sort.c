#include "sort.h"

void quicksort(int *array, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * lomuto_partition - This function uses the Lomuto partition
 * scheme for Quick Sort
 *
 * @array: Pointer to the array to be partitioned
 * @low: Index of the lower bound of the partition
 * @high: Index of the upper bound of the partition
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high)
{
	int i, j;
	int temp, pivot;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	return (i + 1);
}

/**
 * quicksort - This function uses a recursive function to
 * perform Quick Sort
 *
 * @array: Pointer to the array to be sorted
 * @low: Index of the lower bound of the partition
 * @high: Index of the upper bound of the partition
 *
 */
void quicksort(int *array, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, low, high);

		print_array(array, high - low + 1);  /* Print the subarray being sorted */

		quicksort(array, low, pivot_idx - 1);
		quicksort(array, pivot_idx + 1, high);
	}
}

/**
 * quick_sort - This function sorts an array of integers in
 * ascending order using the Quick Sort algorithm with
 * Lomuto partition scheme.
 *
 * @array: Pointer to the array to be sorted
 *
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quicksort(array, 0, size - 1);

	print_array(array, size);  /* Print the entire sorted array */
}
