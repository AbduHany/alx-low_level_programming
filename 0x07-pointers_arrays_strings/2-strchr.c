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
	char *ptr;

	i = 0;
	ptr = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			ptr = (s + i);
			break;
		}
		i++;
	}
	return (ptr);
}
