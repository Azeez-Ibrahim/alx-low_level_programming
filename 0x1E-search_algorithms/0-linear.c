#include "search_algos.h"

/**
 * linear_search - Searches for a value using Linear search algorithm
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in `array`
 * @value: the value to to search for
 *
 * Return: The index of the value if present
 *         -1 if not present
 */
int linear_search(int *array, size_t size, int value)
{
	size_t index;

	if (!array)
		return (-1);

	for (index = 0; index < size; index++)
	{
		printf("Value checked array[%ld] = [%d]\n",
				index, array[index]);
		if (array[index] == value)
		{
			return (index);
		}
	}
	return (-1);
}
