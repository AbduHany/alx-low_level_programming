#include <string.h>
#include "main.h"

/**
 * _strcpy - copies the string pointed to by src to the buffer
 * pointed to by dest.
 * @dest: pointer to the buffer string.
 * @src: pointer to the source string.
 *
 * Return: pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	return (strcpy(dest, src));
}
