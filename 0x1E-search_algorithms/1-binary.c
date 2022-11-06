#include "search_algos.h"
#include <stdlib.h>

/**
 * print_array - Print array
 * @array: Pointer to first element in array
 * @start: Start index
 * @end: End index
 *
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t index;

	printf("Searching in array: ");
	for (index = start; index < end; index++)
	{
		if (index != end - 1)
			printf("%d, ", array[index]);
		else
		{
			printf("%d\n", array[index]);
		}
	}
}


/**
 * binary_search - Searchs for a value in a sorted array using Binary
 * Search algorithm
 *
 * @array: Pointer to first element in array
 * @size: Number of elements in `array`
 * @value: Value to search for
 *
 * Return: index of value in array
 *         -1 if not present
 *
 */
int binary_search(int *array, size_t size, int value)
{
	size_t start = 0, end = size, mid;

	if (!array)
		return (-1);
	while (start < end)
	{
		print_array(array, start, end);
		mid = ((end + start) % 2) == 0 ? ((end + start) - 1) / 2 : (end + start) / 2;
		if (value == array[mid])
		{
			return (mid);
		}
		else if (value > array[mid])
		{
			start = mid + 1;
		}
		else if (value < array[mid])
		{
			end = mid;
		}
	}
	return (-1);
}
