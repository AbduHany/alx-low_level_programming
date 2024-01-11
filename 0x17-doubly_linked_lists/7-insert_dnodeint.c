#include "lists.h"

/**
 * init_new_node - initializes a new node.
 * @n: value to be added in new node.
 *
 * Return: address of the new node, NULL if failed.
 */
dlistint_t *init_new_node(int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: pointer to the head pointer of the doubly linked list.
 * @idx: index of where the new node will be added in the list.
 * @n: value to be added in new node.
 *
 * Return: address of the new node, or NULL if failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp, *temp2;
	int node_count = 0, i;

	if ((*h == NULL && idx != 0) || h == NULL)
		return (NULL);
	else if (*h == NULL && idx == 0) /** adding at idx 0 in empty list **/
		return (add_dnodeint(h, n));

	for (temp = *h; temp != NULL; temp = temp->next)
		node_count++; /** counting the number of nodes in list **/

	if ((int)idx >= node_count) /** checking if index is out of range **/
		return (NULL);

	if ((int)idx == 0)
		return (add_dnodeint(h, n));
	else if ((int)idx == ((node_count) - 1))
		return (add_dnodeint_end(h, n));

	new_node = init_new_node(n); /** initialize new node **/
	if (new_node == NULL)
		return (NULL);
	for (i = 0, temp = *h, temp2 = (*h)->next; i < ((int)idx - 1); i++)
	{
		temp = temp->next;
		temp2 = temp2->next;
	}
	new_node->next = temp2;
	new_node->prev = temp;
	temp->next = new_node;
	temp2->prev = new_node;
	return (new_node);
}
