#include "sort.h"

void swap(int *a, int *b);
void quick_sort_hoare_recursive(int arr[], int low, int high);
int hoare_partition(int arr[], int low, int high);


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int hoare_partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do
		{
			i++;
		}
		while (arr[i] < pivot);

		do
		{
			j--;
		}
		while (arr[j] > pivot);

		if (i >= j)
		{
			return i; /* Return i as the partition index */
		}

		swap(&arr[i], &arr[j]);
		print_array(arr, high + 1);
	}
}

void quick_sort_hoare_recursive(int arr[], int low, int high)
{
	if (low < high)
	{
		int partition_index = hoare_partition(arr, low, high);
		quick_sort_hoare_recursive(arr, low, partition_index);
		quick_sort_hoare_recursive(arr, partition_index + 1, high);
	}
}

void quick_sort_hoare(int arr[], size_t size)
{
	if (size < 2) 
	{
		return; /* Array of size 0 or 1 is already sorted. */
	}
	quick_sort_hoare_recursive(arr, 0, size - 1);
}
