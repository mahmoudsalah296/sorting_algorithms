#include "sort.h"

/**
 * merge - merges the two sorted portions of the array
 * @array: array to be merged
 * @size: size of the array
 * @left: lower bound of the array
 * @right: upper bound of the array
 * @mid: middle of the array
 */
void merge(int array[], size_t size, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left, *output;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);
	while (i <= mid && j <= right)
	{
		if (array[i] < array[j])
		{
			output[k] = array[i];
			i++;
		}
		else
		{
			output[k] = array[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		output[k] = array[i];
		i++;
		k++;
	}
	while (j <= right)
	{
		output[k] = array[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(output + left, right - left + 1);
	for (i = left; i <= right; i++)
		array[i] = output[i];
	free(output);
}

/**
 * merge_sort_recursion - devide the array and sort it
 * @array: the array to be devided
 * @size: size of the array
 * @left: lower bound of the array
 * @right: upper bound of the array
 */
void merge_sort_recursion(int array[], size_t size, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursion(array, size, left, mid);
		merge_sort_recursion(array, size, mid + 1, right);
		merge(array, size, left, mid, right);
	}
}
/**
 * merge_sort - sorts an array of integers in ascending order
 *          using the top-down merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	merge_sort_recursion(array, size, 0, size - 1);
}
