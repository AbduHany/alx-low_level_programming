#include "lists.h"
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: pointer to the head pointer of the linked list.
 * @str: char pointer to string to be added to newly added node.
 *
 * Return: address of new node, or NULL if failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *temp;

	temp = malloc(sizeof(list_t));
	if (temp == NULL)
		return (NULL);
	temp->str = strdup(str);
	temp->next = *head;
	*head = temp;
	return (*head);
}
