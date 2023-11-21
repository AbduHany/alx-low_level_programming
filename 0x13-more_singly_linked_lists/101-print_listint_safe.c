#include "lists.h"

/**
 * check_loop - checks if linked list has a loop or not.
 * @head: pointer to head of linked list.
 *
 * Return: 0 if list contains no loop, number of unique nodes
 * if list contains loop.
 */
size_t check_loop(const listint_t *head)
{
	const listint_t *fast, *slow;
	size_t node_count = 1;

	if (head == NULL || head->next == NULL)
		exit(98);
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
			return (node_count);
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return (0);
}
/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to head of listint_t list.
 *
 * Return: number of nodes in list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count = 0, i;

	node_count = check_loop(head);
	if (node_count == 0)
	{
		while (head != NULL)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
			node_count++;
		}
	}
	else
	{
		for (i = 0; i < node_count; i++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (node_count);
}
