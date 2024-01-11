#include "lists.h"

/**
 * dlistint_len - counts the number of elements in a linked list.
 * @h: head pointer to the linked list.
 *
 * Return: the number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;
	dlistint_t *temp = (dlistint_t *)h;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
