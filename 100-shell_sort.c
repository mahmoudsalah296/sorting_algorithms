#include "sort.h"

/**
 * swap - swap two values
 * @a: first value
 * @b: second value
*/
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order
 *          using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
				swap(&array[j], &array[j - gap]);
		}
		gap /= 3;
		print_array(array, size);
	}
}
