#include "lists.h"

/**
 * sum_listint - sums of all the data (n) of a listint_t linked list.
 * @head: head pointer of listint_t list.
 *
 * Return: the sum value of all data (n) in the list.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp;

	if (head == NULL)
		return (0);
	temp = head;
	while (temp != NULL)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
