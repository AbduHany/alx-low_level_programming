#include "lists.h"

/**
 * printstr - prints a string.
 * @str: char pointer to string.
 *
 * Return: void.
 */
void printstr(char *str, unsigned int len)
{
	if (str == NULL)
	{
		printf("[0] (nil)\n");
		return;
	}
	printf("[%u] %s\n", len, str);
}

/**
 * print_list - prints all the elements of a list_t list.
 * @h: head of a single linked list.
 *
 * Return: number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	int node_count = 0;
	unsigned int len;
	char *str;
	list_t *temp;
	
	if (h == NULL)
	{
		printf("List is empty\n");
		return (0);
	}
	temp = (list_t *) h;
	while (temp != NULL)
	{
		str = temp->str;
		len = temp->len;
		printstr(str, len);
		node_count++;
		temp = temp->next;
	}
	return (node_count);
}
