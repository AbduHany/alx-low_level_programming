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

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if ((*(s + i)) == c)
		{
			ptr = &s[i];
			break;
		}
		else
			ptr = 0;
	}
	return (ptr);
}
