#include "main.h"
#include <ctype.h>
/**
 * _islower - checks if a character is in lowercase.
 * @c: The character to check if lowercase.
 *
 * Return: 1 if character is lowercase
 * if not lowercase, return 0.
 */
int _islower(int c)
{
	if (islower(c) == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
