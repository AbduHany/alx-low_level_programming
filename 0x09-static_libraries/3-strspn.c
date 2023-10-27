#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 * @s: pointer to string whose length will be calculated.
 * @accept: pointer to array of characters to be tested.
 *
 * Return: integer to the number of occurences of the substring.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, flag, count;

	count = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		if (flag == 1)
			break;
	}
	return (count);
}
