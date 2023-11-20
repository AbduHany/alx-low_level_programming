#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: head pointer to the listint_t list.
 *
 * Return: the number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	size_t node_count = 0;
	listint_t *temp;

	if (h == NULL)
		return (0);
	temp = (listint_t *) h;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		node_count++;
		temp = temp->next;
	}
	return (node_count);
}
