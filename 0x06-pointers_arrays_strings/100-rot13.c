#include "main.h"

/**
 * rot13 -  encodes a string using rot13.
 * @s: pointer to string that will be encoded.
 *
 * Return: pointer to encoded string.
 */
char *rot13(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= 'A' && s[i] <= 'M') || (s[i] >= 'a' && s[i] <= 'm'))
		{
			s[i] += 13;
		}
		else if ((s[i] >= 'N' && s[i] <= 'Z') || (s[i] >= 'n' && s[i] <= 'z'))
		{
			s[i] -= 13;
		}
		i++;
	}
	return (s);
}
