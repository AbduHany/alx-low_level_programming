#include "main.h"

/**
 * rot13 -  encodes a string using rot13.
 * @s: pointer to string that will be encoded.
 *
 * Return: pointer to encoded string.
 */
char *rot13(char *s)
{
	int i, j;
	char temp;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	i = 0;
	while (s[i] != '\0')
	{
		temp = s[i];
		for (j = 0; j < 52; j++)
		{
			if (temp == input[j])
			{
				s[i] = output[j];
				break;
			}
			else
				continue;
		}
		i++;
	}
	return (s);
}
