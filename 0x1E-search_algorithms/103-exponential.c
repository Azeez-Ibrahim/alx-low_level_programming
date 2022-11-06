#include "search_algos.h"

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
 * _binary_search - Searchs for a value in a sorted array using Binary
 * Search algorithm
 *
 * @array: Pointer to first element in array
 * @start: Index to start searching for
 * @end: Index to stop searching for
 * @value: Value to search for
 *
 * Return: index of value in array
 *         -1 if not present
 *
 */
int _binary_search(int *array, size_t start, size_t end, int value)
{
	size_t mid;

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



/**
 * exponential_search - Searches for a value using exponential algorithm
 *
 * @array: Pointer to first element in array
 * @size: Number of elements
 * @value: Value to be search for
 *
 * Return: Index of value
 *         -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t jump = 2, index = 1, end;

	if (!array)
		return (-1);

	while (index < size && value > array[index])
	{
		printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		index *= jump;
	}
	end = (index >= size) ? size - 1 : index;
	printf("Value found between indexes [%ld] and [%ld]\n", index / jump, end);
	return (_binary_search(array, index / jump, ++end, value));
}
