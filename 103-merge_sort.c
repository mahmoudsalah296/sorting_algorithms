#include "sort.h"

/**
 * merge - merges two subarrays of integers in ascending order
 * @array: array to be sorted
 * @tmp: temporary array to store the sorted subarray
 * @left: leftmost index of the subarray
 * @mid: middle index of the subarray
 * @right: rightmost index of the subarray
 */
void merge(int *array, int *tmp, int left, int mid, int right)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid + 1);

	for (i = left, j = mid, k = left; k <= right; k++)
	{
		if (i == mid)
			tmp[k] = array[j++];
		else if (j == right + 1)
			tmp[k] = array[i++];
		else if (array[i] < array[j])
			tmp[k] = array[i++];
		else
			tmp[k] = array[j++];
	}

	for (i = left; i <= right; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}
/**
 * merge_sort_recursive - sorts an array of integers in ascending order
 * 		using the top-down merge sort algorithm
 * @array: array to be sorted
 * @tmp: temporary array to store the sorted subarray
 * @left: leftmost index of the subarray
 * @right: rightmost index of the subarray
 */
void merge_sort_recursive(int *array, int *tmp, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort_recursive(array, tmp, left, mid);
		merge_sort_recursive(array, tmp, mid + 1, right);
		merge(array, tmp, left, mid + 1, right);
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
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	merge_sort_recursive(array, tmp, 0, size - 1);
	free(tmp);
}
