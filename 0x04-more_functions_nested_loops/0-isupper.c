#include <ctype.h>
#include "main.h"

/**
 * _isupper - checks for uppercase character.
 * @c: the character that's checked for uppercase.
 *
 * Return: 1 if c is uppercase
 * 0 otherwise.
 */
int _isupper(int c)
{
	if (isupper(c) != 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
