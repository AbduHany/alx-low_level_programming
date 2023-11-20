#include "lists.h"

/**
 * listint_len - counts the number of elements in a listint_t list.
 * @h: head pointer to listint_t list.
 *
 * Return: the number of elements in a listint_t list.
 */
size_t listint_len(const listint_t *h)
{
	size_t listlen = 0;
	listint_t *temp;

	if (h == NULL)
		return (0);
	temp = (listint_t *) h;
	while (temp != NULL)
	{
		listlen++;
		temp = temp->next;
	}
	return (listlen);
}
