#include "lists.h"

/**
 * get_dnodeint_at_index - gets the nth node of a doubly linked list.
 * @head: pointer to the head of a doubly linked list.
 * @index: the index at which the address of the node is to be returned.
 *
 * Return: address of the node at index, NULL if failed.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp;
	int node_count = 0, i;

	if (head == NULL)
		return (NULL);
	/** counting the number of nodes in dlist **/
	for (i = 0, temp = head; temp != NULL; temp = temp->next)
		node_count++;
	if ((int)index >= node_count) /** index isn't bigger than node count **/
		return (NULL);
	temp = head;
	for (i = 0; i < (int)index; i++)
	{
		temp = temp->next;
	}
	return (temp);
}
