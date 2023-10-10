#include "main.h"
#include <ctype.h>

/**
 * _isalpha -  checks for alphabetic character.
 * @c: character that's checked if alphabetic.
 *
 * Return: returns 1 is c is a letter (Lowercase or Uppercase)
 * if not a letter, return 0.
 */
int _isalpha(int c)
{
	if (isalpha(c) == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
