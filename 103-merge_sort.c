#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of the original array
 *
 * @array: Pointer to the original array
 * @left: Starting index of the left subarray
 * @mid: Middle index (end of left subarray)
 * @right: Ending index of the right subarray
 */
void merge(int *array, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int *L = malloc(n1 * sizeof(int));
	int *R = malloc(n2 * sizeof(int));

	if (L == NULL || R == NULL)
	{
		free(L);
		free(R);
		return;
	}

	for (i = 0; i < n1; i++)
		L[i] = array[left + i];
	for (j = 0; j < n2; j++)
		R[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge Sort algorithm.
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	if (size > 1)
	{
		int mid = size / 2;
		int *L = array;
		int *R = array + mid;

		merge_sort(L, mid);
		merge_sort(R, size - mid);
		merge(array, 0, mid - 1, size - 1);

		printf("Merging...\n");
		printf("[left]: ");
		print_array(L, mid);
		printf("[right]: ");
		print_array(R, size - mid);
		printf("[Done]: ");
		print_array(array, size);
	}
}
