#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a doubly linked list.
 * @head: pointer to the head pointer of the doubly linked list.
 * @n: value to be added at the new node.
 *
 * Return: The address of the new element, or NULL if failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

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
	/** adding it to a list that already has nodes **/
	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
	return (new_node);
}
