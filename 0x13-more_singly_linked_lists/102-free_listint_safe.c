#include "lists.h"

/**
 * nodes_to_free - gets number of nodes to be freed if list has loop.
 * @head: pointer to head of linked list.
 *
 * Return: 0 if list contains no loop, number of nodes
 * if list contains loop.
 */
size_t nodes_to_free(listint_t *head)
{
	listint_t *fast, *slow;
	size_t node_count = 0;

	slow = head->next;
	fast = head->next->next;
	while (fast != NULL) /* Floyd's method using hare and tortoise pointers */
	{
		if (fast == slow)
		{
			fast = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
				node_count++;
			}
			fast = fast->next;
			while (fast != slow)
			{
				fast = fast->next;
				node_count++;
			}
			return (node_count + 1);
		}
		slow = slow->next;
		fast = (fast->next)->next;
	}
	return (0);
}
/**
 * free_listint_safe - frees a listint_t list.
 * @h: pointer to head pointer of listint_t list.
 *
 * Return: number of nodes freed in list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t node_count = 0, i;
	listint_t *temp;

	if (*h == NULL)
		return (0);
	node_count = nodes_to_free(*h);
	if (node_count == 0)
	{
		temp = *h;
		while (temp != NULL)
		{
			temp = temp->next;
			free(*h);
			*h = temp;
			node_count++;
		}
		*h = NULL;
		h = NULL;
		return (node_count++);
	}
	else
	{
		temp = *h;
		for (i = 0; i < node_count; i++)
		{
			temp = temp->next;
			free(*h);
			*h = temp;
		}
		*h = NULL;
		h = NULL;
	}
	return (node_count);
}
