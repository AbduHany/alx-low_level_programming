#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: pointer of destination string concatenation.
 * @src: pointer of source string concatenation.
 *
 * Return: Char pointer to concatenated string.
 */
char *_strcat(char *dest, char *src)
{
	int i, len;

	len = 0;
	for (i = 0; dest[i] != '\0'; i++)
	{
		len++;
	}
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}
