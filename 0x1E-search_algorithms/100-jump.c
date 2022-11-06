#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Searches for a number using the Jump Search algorithm
 *
 * @array: Pointer to first element
 * @size: Number of elements
 * @value: Value to search for
 *
 * Return: Index of value
 *         -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump, index = 0, i;

	if (!array)
		return (-1);
	jump = (size_t)sqrt(size);
	while (index < size && value > array[index])
	{
		printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		index += jump;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", index - jump, index);
	for (i = index - jump; i <= index; i++)
	{
		if (i == size)
			break;
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (value == array[i])
			return (i);
	}
	return (-1);
}
