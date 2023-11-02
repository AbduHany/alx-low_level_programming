#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: pointer to the first string.
 * @s2: pointer to the second string.
 * @n: number of bytes to concatenate from s2.
 *
 * Return: character pointer to concatenated string.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, len1, len2;
	char *p;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0, len1 = 0; s1[i] != '\0'; i++)
		len1++;
	for (i = 0, len2 = 0; s2[i] != '\0'; i++)
		len2++;
	if (n >= len2)
		n = len2;
	p = malloc((len1 + n + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		p[i] = s1[i];
	for (i = 0; i < n; i++)
		p[i + len1] = s2[i];
	p[len1 + n] = '\0';
	return (p);

}
