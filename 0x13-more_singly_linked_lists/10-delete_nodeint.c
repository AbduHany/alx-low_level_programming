#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of a
 * listint_t linked list.
 *
 * @head: pointer to the head pointer of listint_t list.
 * @index: index of node to be deleted.
 *
 * Return: 1 if succeeded and -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *before, *after;
	unsigned int i, node_count;

	if (head == NULL || *head == NULL)
		return (-1);
	current = *head; /* counting the number of nodes */
	for (node_count = 0; current != NULL; current = current->next)
		node_count++;
	if (index > (node_count - 1)) /* if index is bigger that node count */
		return (-1);
	current = *head;
	before = *head;
	if (index == 0) /* removing 0th node */
	{
		current = current->next;
		free(*head);
		*head = current;
		return (1);
	}
	else if (index == (node_count - 1)) /* removing last node */
	{
		while (current->next->next != NULL)
			current = current->next;
		free(current->next);
		current->next = NULL;
		return (1);
	}
	current = current->next; /* removing node at index */
	after = current->next;
	for (i = 0; i < (index - 1); i++)
	{
		after = after->next;
		current = current->next;
		before = before->next;
	}
	free(current);
	before->next = after;
	return (1);

}
