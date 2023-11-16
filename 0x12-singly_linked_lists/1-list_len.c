#include "lists.h"

/**
 * list_len -  counts the number of elements in a linked list_t list.
 * @h: head pointer to linked list.
 *
 * Return: number of elements in a linked list.
 */
size_t list_len(const list_t *h)
{
	size_t el_count = 0;
	list_t *temp;

	if (h == NULL)
		return (0);
	temp = (list_t *) h;
	while (temp != NULL)
	{
		el_count++;
		temp = temp->next;
	}
	return (el_count);
}
