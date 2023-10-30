#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: pointer to first string.
 * @s2: pointer to second string.
 *
 * Return: char pointer to newly concatenated
 * string.
 */
char *str_concat(char *s1, char *s2)
{
	int len1, len2, i;
	char *con;

	len1 = len2 = 0;
	for (i = 0, len1 = 0; s1[i] != '\0'; i++)
		len1++;
	for (i = 0, len2 = 0; s2[i] != '\0'; i++)
		len2++;
	con = malloc((len1 + len2 + 1) * sizeof(char));
	if (con == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		con[i] = s1[i];
	for (i = 0; i < len2; i++)
		con[len1 + i] = s2[i];
	con[len1 + len2] = '\0';
	return (con);
}
