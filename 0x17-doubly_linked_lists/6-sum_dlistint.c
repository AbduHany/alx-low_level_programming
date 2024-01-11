#include "lists.h"

/**
 * sum_dlistint - add all the data of a doubly linked list.
 * @head: head pointer of a doubly linked list.
 *
 * Return: value of the sum, 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *cursor = head;

	if (head == NULL) /** if list is empty **/
		return (0);
	while (cursor != NULL)
	{
		sum += cursor->n;
		cursor = cursor->next;
	}
	return (sum);
}
