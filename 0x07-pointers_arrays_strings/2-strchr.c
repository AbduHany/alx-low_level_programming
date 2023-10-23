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

	i = 0;
	p = 0;
	while (*(s + i) != '\0' || *(s + i) == '\0')
	{
		if (*(s + i) == c)
		{
			p = &(*(s + i));
			break;
		}
		i++;
	}
	return (p);
}
