#include "lists.h"

/**
 * free_listint2 - frees a listint_t list.
 * @head: pointer to head pointer of listint_t list.
 *
 * Return: void.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (*head == NULL)
	{
		printf("List is already empty.\n");
		return;
	}
	temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
		free(*head);
		*head = temp;
	}
	head = NULL;
}
