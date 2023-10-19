#include "main.h"

/**
 * cap_string - capitalizes all words of a string.
 * @s: pointer to string whose words are capitalized.
 *
 * Return: pointer to capitalized string.
 */
char *cap_string(char *s)
{
	int i, len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	if (s[0] >= 'a' && s[0] <= 'z')
	{
		s[0] -= 32;
	}
	for (i = 0; i < len; i++)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
		s[i] == ',' || s[i] == ';' || s[i] == '.' ||
		s[i] == '!' || s[i] == '?' || s[i] == '"' ||
		s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}')
		{
			if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
			{
				s[i + 1] -= 32;
			}
		}

	}
	return (s);
}
