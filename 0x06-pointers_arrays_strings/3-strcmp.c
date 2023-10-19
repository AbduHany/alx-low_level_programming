#include "main.h"

/**
 * _strcmp - compares two strings.
 * @s1: pointer to first string being compared.
 * @s2: pointer to second string being compared.
 *
 * Return: 0 if idential
 * Non-zero int value if non-identical.
 */
int _strcmp(char *s1, char *s2)
{
	int i, diff;

	i = 0;
	diff = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((s1[i] - s2[i]) == 0)
		{
			i++;
		}
		else
		{
			diff = s1[i] - s2[i];
			break;
		}
	}
	return (diff);
}
