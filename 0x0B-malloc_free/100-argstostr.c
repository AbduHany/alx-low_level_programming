#include "main.h"
#include <stdlib.h>

/**
 * argstostr -  concatenates all the arguments of your program.
 * @ac: arguments count.
 * @av: arguments string array.
 *
 * Return: char pointer to concatenated string.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, sum;
	char *s;

	sum = 0;
	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			sum++;
			j++;
		}
	}
	sum++;
	s = malloc((sum + ac) * sizeof(char));
	if (s == NULL)
		return (NULL);
	for (i = 0, k = 0; i < ac; i++, k++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			*(s + k) = av[i][j];
			k++;
			j++;
		}
		*(s + k) = '\n';
	}
	*(s + k) = '\0';
	return (s);
}
