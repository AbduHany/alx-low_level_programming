#include "main.h"

/**
 * leet - encodes a string into 1337.
 * @s: pointer to string to be encoded.
 *
 * Return: pointer to encoded string.
 */
char *leet(char *s)
{
	int i, j;
	char *upper, *lower, *code;

	i = 0;
	upper = "AEOTL";
	lower = "aeotl";
	code = "43071";
	while (s[i] != '\0')
	{
		for (j = 0; j < 5; j++)
		{
			if (s[i] == upper[j] || s[i] == lower[j])
			{
				s[i] = code[j];
			}
		}
		i++;
	}
	return (s);

}
