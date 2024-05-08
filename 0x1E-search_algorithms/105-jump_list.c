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
	size_t jump, lowidx, highidx;
	listint_t *low, *high, *cursor;

	(void)low;
	if (list == NULL)
		return (NULL);
	jump = sqrt(size);
	low = high = list;
	lowidx = 0;
	highidx = jump;
	while (high->index != highidx)
		high = high->next;
	while (high->next != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n", high->index, high->n);
	        if (value >= low->n && value <= high->n)
			break;
	        lowidx += jump;
		highidx += jump;
		while (low->index != lowidx)
			low = low->next;
		while (high->index != highidx && high->next != NULL)
			high = high->next;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", low->index, high->index);
	cursor = low;
	while (cursor != high->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", cursor->index, cursor->n);
		if (cursor->n == value)
			return cursor;
		cursor = cursor->next;
	}
	return (NULL);
}
