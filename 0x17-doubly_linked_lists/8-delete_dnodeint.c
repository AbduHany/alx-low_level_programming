#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index
 * of a dlinked list.
 * @head: pointer to the head pointer of the doubly linked list.
 * @index: index of node to be deleted.
 *
 * Return: 1 if successfull, -1 if failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	int node_count = 0, i;

	if ((*head) == NULL || head == NULL)
		return (-1);
	for (temp = *head; temp != NULL; temp = temp->next)
		node_count++; /** counting the number of nodes in list **/
	if ((int)index >= node_count)
		return (-1);
	else if (index == 0)
	{
		if (node_count == 1)
		{
			free(*head);
			*head = NULL;
			return (1);
		}
		temp = (*head)->next;
		free(*head);
		*head = temp;
		(*head)->prev = NULL;
		return (1);
	}
	else if ((int)index == (node_count - 1))
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->prev->next = NULL;
		free(temp);
		return (1);
	}
	for (temp = *head, i = 0; i < (int)index; i++)
		temp = temp->next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
	return (1);
}
