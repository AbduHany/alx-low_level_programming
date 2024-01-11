#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 * @h:head pointer of a doubly linked list.
 *
 * Return: number of nodes in list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	dlistint_t *temp = (dlistint_t *)h;
	size_t count = 0;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		count++;
		temp = temp->next;
	}
	return (count);
}
