#include "lists.h"
#include <stdio.h>

/**
 * printstr - prints a string.
 * @str: char pointer to string.
 * @len: length of the string.
 *
 * Return: void.
 */
void printstr(char *str, int len)
{
	if (str == NULL)
	{
		printf("[0] (nil)\n");
	}
	else
		printf("[%d] %s\n", len, str);
}

/**
 * _strlen - calculates length of a string.
 * @str: char pointer to string.
 *
 * Return: length of string.
 */
int _strlen(char *str)
{
	int len = 0, i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		len++;
	return (len);
}

/**
 * print_list - prints all the elements of a list_t list.
 * @h: head of a single linked list.
 *
 * Return: number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t node_count = 0;
	int len;
	char *str;
	list_t *temp;

	if (h == NULL)
	{
		return (0);
	}
	temp = (list_t *) h;
	while (temp != NULL)
	{
		str = temp->str;
		len = _strlen(str);
		printstr(str, len);
		node_count++;
		temp = temp->next;
	}
	return (node_count);
}
