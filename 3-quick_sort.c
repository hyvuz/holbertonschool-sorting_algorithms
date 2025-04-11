#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	if (a != b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: The array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array (for print_array)
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_recursive - Recursively sorts the array
 * @array: The array to sort
 * @low: The lower index
 * @high: The higher index
 * @size: Size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quicksort_recursive(array, low, pivot_index - 1, size);
		quicksort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array using Quick Sort (Lomuto)
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
