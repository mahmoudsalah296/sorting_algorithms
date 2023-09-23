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
 * selection_sort - sorts an array of integers in ascending order
 *              using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_index;

    if (array == NULL || size < 2)
        return;
    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j ++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }
        if (min_index != i)
        {
            swap(&array[i], &array[min_index]);
            print_array(array, size);
        }
    }
}
