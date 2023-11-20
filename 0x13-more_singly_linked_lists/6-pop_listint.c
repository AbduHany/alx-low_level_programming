#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to head pointer of the listint_t list.
 *
 * Return: the head node's data.
 */
int pop_listint(listint_t **head)
{
	int a;
	listint_t *temp;

	if (*head == NULL)
		return (0);
	temp = *head;
	a = temp->n;
	temp = temp->next;
	free(*head);
	*head = temp;
	return (a);
}
