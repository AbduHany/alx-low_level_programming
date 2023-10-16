#include "main.h"
#include <string.h>

/**
 * puts_half -  prints half of a string, followed by a new line.
 * @str: pointer to string whose half is to be printed.
 *
 * Return: void.
 */
void puts_half(char *str)
{
	int i, length;

	length = strlen(str);
	if ((length % 2) == 0)
	{
		for (i = length / 2; i < length; i++)
		{
			_putchar(*(str + i));
		}
	}
	else
	{
		for (i = ((length / 2) + 1); i < length; i++)
		{
			_putchar(*(str + i));
		}
	}
	_putchar('\n');
}
