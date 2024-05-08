#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: the head node of the linked list being searched.
 * @value: target value being searched for in list.
 *
 * Return: the first node where value is located,
 * or NULL is list head is NULL or value wasn't found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *low, *high, *cursor;

	if (list == NULL)
		return (NULL);
	low = list;
	high = low->express;
	while (high->express != NULL)
	{
		if (value >= low->n && value <= high->n)
			break;
		printf("Value checked at index [%ld] = [%d]\n", high->index, high->n);
		low = low->express;
		high = high->express;
	}
	if (value > high->n)
	{
		low = high;
		while (high->next != NULL)
			high = high->next;
	}
	printf("Value checked at index [%ld] = [%d]\n", high->index, high->n);
	printf("Value found between indexes [%ld] and [%ld]\n",
	       low->index, high->index);
	cursor = low;
	while (cursor != high->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", cursor->index, cursor->n);
		if (cursor->n == value)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}
