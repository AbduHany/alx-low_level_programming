#include "search_algos.h"

/**
 * jump_list -  searches for a value in a sorted list of integers
 * using the Jump search algorithm.
 * @list: the head node of the linked list being searched.
 * @size: the size of the list being searched.
 * @value: target value being searched for in list.
 *
 * Return: the first node where value is located,
 * or NULL is list head is NULL or value wasn't found.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, idx;
	listint_t *low, *high;

	(void)low;
	if (list == NULL)
		return (NULL);
	jump = sqrt(size);
	low = high = list;
	while (high->index != jump)
		high = high->next;
	while (high != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n", high->index, high->n);
		if (high->n == value)
			return (high);
	}
	return (NULL);
}
