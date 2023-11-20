#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: pointer to the head pointer of the listint_t list.
 * @idx: index of the newly added node.
 * @n: value of the newly created node.
 *
 * Return: the address of the new node
 * NULL if failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int node_count, i;
	listint_t *temp, *new, *before;

	if (head == NULL)
		return (NULL);

	temp = *head; /* counting the number of nodes */
	for (node_count = 0; temp != NULL; temp = temp->next)
		node_count++;
	if (idx > node_count)
		return (NULL);

	new = malloc(sizeof(listint_t)); /* creating new node */
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;

	if (idx == 0) /* adding new node at idx 0 */
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	else if (idx == node_count)
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		return (new);
	}
	before = *head;
	temp = before->next;
	for (i = 0; i < (idx - 1); i++)
	{
		before = before->next;
		temp = temp->next;
	}
	new->next = temp;
	before->next = new;
	return (new);
}
