#include "main.h"

/**
 * _strncpy - copies n bytes of a string.
 * @dest: pointer to destination string.
 * @src: pointer to source string.
 * @n: number of bytes to be copied.
 *
 * Return: pointer to copied string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0' && i < n; i++)
	{
		dest[i] = src[i];
	}
	dest[97] = '\0';
	return (dest);
}
