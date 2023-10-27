#include <ctype.h>
#include "main.h"

/**
 * _isdigit -  checks for a digit (0 through 9).
 * @c: the character that is checked for a digit.
 *
 * Return: 1 if c is a digit.
 * 0 if otherwise.
 */
int _isdigit(int c)
{
	if (isdigit(c) != 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
