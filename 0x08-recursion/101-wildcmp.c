#include "main.h"

/**
 * wildcmp -  compares two strings if identical
 * @s1: pointer to first string.
 * @s2: pointer to second string.
 *
 * Return: 1 if identical
 * 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*(s1) == '\0' && *(s2) == '\0')
	{
		return (1);
	}
	else if (*(s1) == *(s2))
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
	else if (*(s2) == '*')
	{
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	else
		return (0);
}
