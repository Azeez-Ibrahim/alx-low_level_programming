#include "search_algos.h"

/**
 * linear_skip - Searchs a value in a skip list
 *
 * @list: Pointer to the head of skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located
 *         NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp = list, *old;
	size_t size;

	if (!list)
		return (NULL);

	while (tmp != NULL && value > tmp->n)
	{
		old = tmp;
		tmp = tmp->express;
		if (tmp != NULL)
			printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
	}
	if (tmp != NULL)
	{
		printf("Value found between indexes [%ld] and [%ld]\n",
				old->index, tmp->index);
	}
	else
	{
		tmp = old;
		size = tmp->index - 1;
		while (tmp != NULL)
			size++, tmp = tmp->next;
		printf("Value found between indexes [%ld] and [%ld]\n", old->index, size);
	}
	while (old != tmp)
	{
		printf("Value checked at index [%ld] = [%d]\n", old->index, old->n);
		if (value == old->n)
			return (old);
		old = old->next;
	}
	return (NULL);
}
