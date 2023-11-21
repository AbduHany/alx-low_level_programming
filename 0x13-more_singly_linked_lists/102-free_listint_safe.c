#include "lists.h"

/**
 * check_loop - checks if linked list has a loop or not.
 * @head: pointer to head of linked list.
 *
 * Return: 0 if list contains no loop, number of unique nodes
 * if list contains loop.
 */
size_t check_loop(listint_t *head)
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
	node_count = check_loop(*h);
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
		h = NULL;
	}
	return (node_count);
}
