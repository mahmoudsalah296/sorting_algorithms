#include "sort.h"

/**
 * counting_sort -  sorts an array of integers in ascending order
 *          using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	int *output, *count, max, i;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		output[--count[array[i]]] = array[i];
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = output[i];
	}
	free(count);
	free(output);
}
