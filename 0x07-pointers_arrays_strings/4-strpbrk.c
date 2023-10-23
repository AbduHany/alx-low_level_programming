#include "main.h"

/**
 * _strpbrk -  searches a string for any of a set of bytes.
 * @s: pointer to string to search in.
 * @accept: pointer to array of bytes to search for.
 *
 * Return: pointer to the first occurence of character in string.
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j, flag;
	char *p;

	p = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				p = &s[i];
				flag = 1;
				break;
			}
			else
				flag = 0;
		}
		if (flag == 1)
			break;
	}
	return (p);
}
