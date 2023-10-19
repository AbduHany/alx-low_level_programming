#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase.
 * @s: string whose all lowercase letter are changed to uppercase.
 *
 * Return: pointer to the converted string.
 */
char *string_toupper(char *s)
{
	int i, len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	for (i = 0; i < len; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
	}
	return (s);
}
