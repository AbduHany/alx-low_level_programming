#include "lists.h"

/**
 * add_dnodeint_end -  adds a new node at the end of a doubly linked list.
 * @head: pointer to the head pointer of a doubly linked list.
 * @n: value to be added to new node.
 *
 * Return: the address of the new element, or NULL if failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *cursor = *head;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL) /** adding the first node to empty list **/
	{
		*head = new_node;
		return (new_node);
	}
	/** adding it to a end of list that already has nodes **/
	while (cursor->next != NULL)
		cursor = cursor->next;
	new_node->prev = cursor;
	cursor->next = new_node;
	return (new_node);

}
