#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to head of listint_t list.
 * @index: the index of the node to be returned.
 *
 * Return: pointer to the nth node of listint_t list.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int node_count = 0, i;
	listint_t *temp;

	temp = head;
	while (temp != NULL)
	{
		node_count++;
		temp = temp->next;
	}
	if (index > (node_count - 1))
		return (NULL);
	temp = head;
	for (i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return (temp);
}
