#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: pointer to the string to be copied.
 *
 * Return: pointer to character to newly allocated space in memory.
 */
char *_strdup(char *str)
{
	char *cpy;
	int i;

	if (str == NULL)
		return (NULL);
	cpy = malloc(sizeof(char));
	if (cpy == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		cpy[i] = str[i];
	}
	cpy[i] = '\0';
	return (cpy);

}
