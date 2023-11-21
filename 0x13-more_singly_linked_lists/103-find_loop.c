#include "lists.h"

/**
 * get_loop_start - gets the pointer of where a loop starts in a list.
 * @head: pointer to head of linked list.
 *
 * Return: NULL if list contains no loop, pointer of where a loop
 * starts in a list.
 */
listint_t *get_loop_start(listint_t *head)
{
	listint_t *fast, *slow;

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
			}
			return (fast);
		}
		slow = slow->next;
		fast = (fast->next)->next;
	}
	return (NULL);
}
/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to head of listint_t list.
 *
 * Return: address of node where the loop starts or
 * NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	if (head == NULL)
		return (NULL);
	return (get_loop_start(head));
}
