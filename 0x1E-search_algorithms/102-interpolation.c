#include "search_algos.h"
#include <stdlib.h>

/**
 * interpolation_search - Search for a value using Interpolation Search
 *
 * @array: Pointer to the first element
 * @size: Number of elements
 * @value: Value to search for
 *
 * Return: Index of value
 *         -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t start = 0, end = size - 1, pos;

	if (!array)
		return (-1);

	while (start < end)
	{
		pos = start + (((double)(end - start) / (array[end] - array[start])) *
				(value - array[start]));
		if (pos >= size)
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			return (-1);
		}
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (value == array[pos])
			return (pos);
		else if (value > array[pos])
		{
			start = pos + 1;
		}
		else if (value < array[pos])
			end = pos - 1;
	}
	return (-1);
}
