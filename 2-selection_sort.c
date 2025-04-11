#include "sort.h"
/**
 * _swap - Function to swap the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
*/
void _swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Function to sort an array of integers in ascending order
 * using the Selection Sort algorithm.
 * @array: Pointer to the array of integers to be sorted.
 * @size: Number of elements in the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, minor;

	for (i = 0; i < size - 1; i++)
	{
		minor = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minor])
			{
				minor = j;
			}
		}

		if (minor != i)
		{
			_swap(&array[i], &array[minor]);
			print_array(array, size);
		}
	}
}
