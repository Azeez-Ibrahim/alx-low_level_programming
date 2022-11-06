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
 * recursive_search - Recursion
 *
 * @array: Pointer to first element
 * @start: Start Index
 * @end: End index
 * @value: Value to search for
 *
 * Return: Index of value
 *         -1 if not found
 */
int recursive_search(int *array, size_t start, size_t end, int value)
{
	size_t mid;
	int index;

	if (start >= end)
		return (-1);
	print_array(array, start, end);
	mid = ((end + start) % 2 == 0) ? (end + start - 1) / 2 : (end + start) / 2;
	if (array[mid] == value)
	{
		if (array[mid - 1] != value)
			return (mid);
		recursive_search(array, start, mid + 1, value);
		return (mid - 1);
	}
	else if (value > array[mid])
		index = recursive_search(array, mid + 1, end, value);
	else if (value < array[mid])
		index = recursive_search(array, start, mid + 1, value);
	return (index);
}

/**
 * advanced_binary - Searches for a value in an array
 *
 * @array: Pointer to first element in array
 * @size: Number of elements
 * @value: Value to search for
 *
 * Return: Index of value
 *         -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (recursive_search(array, 0, size, value));
}
