#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *created_table;
	shash_node_t **array;

	if (size == 0)
		return (NULL);
	created_table = malloc(sizeof(shash_table_t));
	if (created_table == NULL)
		return (NULL);
	array = calloc(size, sizeof(shash_node_t *));
	if (array == NULL)
	{
		free(created_table);
		return (NULL);
	}
	created_table->size = size;
	created_table->array = array;
	created_table->shead = NULL;
	created_table->stail = NULL;
	return (created_table);
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *newentry, *cursor;
	char *nodekey, *nodeval;
	unsigned long int newindex;

	if (ht == NULL || key == NULL || value == NULL || *key == '\0')
		return (0);
	newentry = malloc(sizeof(shash_node_t));
	if (newentry == NULL)
		return (0);
	nodekey = strdup(key);
	if (nodekey == NULL)
	{
		free(newentry);
		return (0);
	}
	nodeval = strdup(value);
	if (nodeval == NULL)
	{
		free(newentry);
		free(nodekey);
		return (0);
	}
	newentry->key = nodekey;
	newentry->value = nodeval;
	cursor = ht->shead;
	while (cursor)
	{
		if (strcmp(cursor->key, nodekey) == 0)
		{
			free(cursor->value);
			cursor->value = nodeval;
			free(newentry->key);
			free(newentry);
			return (1);
		}
		cursor = cursor->snext;
	}
	newindex = key_index((const unsigned char *)newentry->key, ht->size);
	newentry->next = ht->array[newindex];
	ht->array[newindex] = newentry;

	if (ht->shead == NULL)
	{
		newentry->sprev = NULL;
		newentry->snext = NULL;
		ht->stail = newentry;
		ht->shead = newentry;
	}
	else if (strcmp(ht->shead->key, nodekey) > 0)
	{
		newentry->sprev = NULL;
	        newentry->snext = ht->shead;
		ht->shead->sprev = newentry;
		ht->shead = newentry;
	}
	else
	{
		cursor = ht->shead;
		while (cursor->snext != NULL && strcmp(cursor->snext->key, nodekey) < 0)
			cursor = cursor->snext;
		newentry->snext = cursor->snext;
		newentry->sprev = cursor;
		if (cursor->snext == NULL)
			ht->stail = newentry;
		else
			cursor->snext->sprev = newentry;
		cursor->snext = newentry;
	}
	return (1);
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *cursor;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	if(ht->array[index] == NULL)
		return (NULL);
	cursor = ht->array[index];
	while (cursor != NULL)
	{
		if (strcmp(key, cursor->key) == 0)
			return (cursor->value);
		cursor = cursor->next;
        }
	return NULL;
}

void shash_table_print(const shash_table_t *ht)
{
        shash_node_t *cursor;

	if (ht->shead == NULL)
		return;
	cursor = ht->shead;
	printf("{");
	while (cursor != NULL)
	{
		printf("'%s': '%s'", cursor->key, cursor->value);
		cursor = cursor->snext;
		if (cursor != NULL)
			printf(", ");
	}
	printf("}\n");
	return;
}

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *cursor;

	if (ht->stail == NULL)
		return;
	cursor = ht->stail;
	printf("{");
	while (cursor != NULL)
	{
		printf("'%s': '%s'", cursor->key, cursor->value);
		cursor = cursor->sprev;
		if (cursor != NULL)
			printf(", ");
	}
	printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
	unsigned long int tablesize, i;
	shash_node_t *cursor, *cursor2;

	if (ht == NULL || ht->array == NULL)
		return;
	tablesize = ht->size;
	for (i = 0; i < tablesize; i++)
	{
		if (ht->array[i])
		{
			cursor = ht->array[i];
			while (cursor != NULL)
			{
				cursor2 = cursor->next;
				free(cursor->key);
				free(cursor->value);
				free(cursor);
				cursor = cursor2;
			}
		}
	}
	free(ht->array);
	free(ht);
}
