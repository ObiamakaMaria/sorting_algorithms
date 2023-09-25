#include "sort.h"

/**
 * counting_sort - This functio sorts an array of integers in
 * ascending order using the Counting Sort algorithm.
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max;
	int *count;
	int *output;

	if (array == NULL || size <= 1)
		return;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		return;
	}

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}
	/* Cast max to size_t */

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i < size; i--)
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	for (i = 0; i < size; i++)
		array[i] = output[i];
	print_array(count, max + 1);
	free(count);
	free(output);
}
