#include "lists.h"
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: pointer to the head pointer of the linked list.
 * @str: string to be copied in the newly added node.
 *
 * Return: address of the newly added node.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *cursor;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		cursor = *head;
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = new;
	}
	return (new);
}
