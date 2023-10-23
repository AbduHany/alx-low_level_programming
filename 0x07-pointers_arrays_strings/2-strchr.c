#include "main.h"

/**
 * _strchr - locates a character in a string.
 * @s: pointer to string to be analyzed.
 * @c: character that occurs in string.
 *
 * Return: pointer to the first occurrence of c in s.
 */
char *_strchr(char *s, char c)
{
	int i;
	char *p;

	p = 0;
	for (i = 0; s[i] >= '\0'; i++)
	{
		if (*(s + i) == c)
		{
			p = &(*(s + i));
			break;
		}
	}
	return (p);
}
