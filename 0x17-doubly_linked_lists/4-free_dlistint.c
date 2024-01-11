#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: pointer to the head of the doubly linked list.
 *
 * Return: void.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *cursor = head;

	while (cursor != NULL)
	{
		cursor = cursor->next;
		free(head);
		head = cursor;
	}
}
