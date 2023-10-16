#include "main.h"
#include <string.h>

/**
 * puts2 - prints every other character of a string,
 * starting with the first character.
 * @str: pointer to the string whose every other character will be printed
 *
 * Return: void.
 */
void puts2(char *str)
{
	int length, i;

	length = strlen(str);
	for (i = 0; i < length; i++)
	{
		if ((i % 2) == 0)
		{
			_putchar(*(str + i));
		}
	}
	_putchar('\n');
}
