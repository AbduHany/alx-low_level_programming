#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog.
 * @name: pointer to dogs name
 * @age: float of dogs age
 * @owner: pointer to dogs owner.
 *
 * Return: pointer to created struct dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	if (name == NULL || owner == NULL)
		return (NULL);
	dog_t *tmp;
	char *cpname, *cpowner;
	int name_len, owner_len, i;

	for (i = 0, name_len = 0; name[i] != '\0'; i++)
		name_len++;
	for (i = 0, owner_len = 0; owner[i] != '\0'; i++)
		owner_len++;
	cpname = malloc(sizeof(char) * (name_len + 1));
	if (cpname == NULL)
		return (NULL);
	cpowner = malloc(sizeof(char) * (owner_len + 1));
	if (cpowner == NULL)
		return (NULL);
	for (i = 0; i < name_len; i++)
		cpname[i] = name[i];
	cpname[i] = '\0';
	for (i = 0; i < owner_len; i++)
		cpowner[i] = owner[i];
	cpowner[i] = '\0';
	tmp = malloc(sizeof(struct dog));
	if (tmp == NULL)
		return (NULL);
	tmp->name = cpname;
	tmp->age = age;
	tmp->owner = cpowner;
	return (tmp);
}
