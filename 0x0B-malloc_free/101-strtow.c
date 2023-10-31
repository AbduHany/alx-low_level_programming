#include "main.h"
#include <stdlib.h>
/**
 * wordlens - count every word's length.
 * @str: pointer to string.
 * @word_count: number of words.
 *
 * Return: returns an int pointer to lengths array.
 */
int *wordlens(char *str, int word_count)
{
	int *arr;
	int i, j, count;

	arr = malloc(word_count * sizeof(int));
	if (arr == NULL)
		return (NULL);
	j = 0;
	for (i = 0; i < word_count; i++)
	{
		count = 0;
		while (str[j] != '\0')
		{
			if (str[j] == ' ' && str[j + 1] == ' ')
				j++;
			if (str[j] != ' ')
				count++;
			if (str[j + 1] == ' ' && str[j] != ' ')
			{
				j++;
				break;
			}
			j++;
		}
		arr[i] = count;
	}
	return (arr);
}

/**
 * countwords - counts number of space separated words
 * in a string.
 * @str: pointer to string to be counted.
 *
 * Return: number of words
 */
int countwords(char *str)
{
	int i, word_count;

	word_count = 0;
	for (i = 1; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			if (str[i - 1] != ' ')
				word_count++;
			else
				continue;
		}
	}
	return (word_count);
}
/**
 * strtow - splits a string into words.
 * @str: pointer to string to be split.
 *
 * Return: a double char pointer to the array of words.
 */
char **strtow(char *str)
{
	int word_count, i, j, k, *word_lens;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);
	word_count = countwords(str);
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	word_lens = wordlens(str, word_count);
	k = 0;
	for (i = 0; i < word_count; i++)
	{
		words[i] = (char *) malloc((word_lens[i] + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(words[k]);
			return (NULL);
		}
	}
	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		k = 0;
		while (str[i] != '\0')
		{
			if (str[i] != ' ')
			{
				if (str[i + 1] == ' ')
				{
					words[j][k] = str[i];
					k++;
					break;
				}
				else
				{
					words[j][k] = str[i];
					k++;
					i++;
				}
			}
			else if (str[i] == ' ')
				i++;
		}
		if (str[i] == '\0')
			break;
		words[j][k] = '\0';
		j++;
	}
	free(word_lens);
	words[word_count] = NULL;
	return (words);
}
