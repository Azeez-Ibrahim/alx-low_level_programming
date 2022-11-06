#ifndef SEARCH_ALGOS
#define SEARCH_ALGOS

/* Header Files */
#include <stdio.h>

/**
 * struct listint_s - Singly linked list
 *
 * @h: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: Singly linked list node structure
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

/* Function Prototypes */
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);


#endif /* SEARCH_ALGOS */
