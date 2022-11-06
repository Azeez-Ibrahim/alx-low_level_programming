#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Searches for a value in singly linked list
 *
 * @list: Pointer to head of singly linked list
 * @size: Number of nodes
 * @value: Value to be searched for
 *
 * Return: Pointer to node where value is loacted
 *         NULL if not found
 *
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *tmp = NULL, *old = NULL;
	size_t jump, index = 0, track = 0;

	if (!list)
		return (NULL);

	jump = (size_t)sqrt(size);
	tmp = list;
	while (index < size && tmp != NULL && value > tmp->n)
	{
		index += jump;
		old = tmp;
		index = (index >= size) ? size : index;
		while (track < index && tmp->next != NULL)
			track++, tmp = tmp->next;
		printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			old->index, tmp->index);
	while (old != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n", old->index, old->n);
		if (value == old->n)
			return (old);
		old = old->next;
	}
	return (NULL);
}
