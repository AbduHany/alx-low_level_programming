#include "lists.h"

/**
 * check_loop - checks if linked list has a loop or not.
 * @head: pointer to head of linked list.
 *
 * Return: 0 if list contains no loop, number of unique nodes
 * if list contains loop.
 */
listint_t *get_loop_start(listint_t *head)
{
	const listint_t *fast, *slow;
	size_t node_count = 1;

	if (head->next == NULL)
		return (0);
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
			return (fast);
		}
		slow = slow->next;
		fast = (fast->next)->next;
	}
	return (NULL);
}
/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to head of listint_t list.
 *
 * Return: number of nodes in list.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *temp;

	if (head == NULL)
		exit(98);
	temp = get_loop_start(head);
	if (temp == NULL)
	{
		return (NULL);
	}
	return (temp);
}
