#include "hash_tables.h"

/**
 * add_to_table - adds a new entry to a hash table after checking there
 * are no duplicate keys.
 * @newentry: pointer to the new hash node to be added.
 * @ht: pointer to the hash table struct.
 *
 * Return: 1 if success, 0 if not.
 */
int add_to_table(hash_node_t *newentry, hash_table_t *ht)
{
	hash_node_t *cursor;
	unsigned long int newindex;

	newindex = key_index((const unsigned char *)newentry->key, ht->size);
	if ((*((ht->array) + newindex)) != NULL)
	{
		cursor = ht->array[newindex];
		while (cursor != NULL)
		{
			if (strcmp(newentry->key, cursor->key) == 0)
			{
				free(cursor->value);
				cursor->value = newentry->value;
				free(newentry->key);
				free(newentry);
				return (1);
			}
			cursor = cursor->next;
		}
		cursor = (ht->array)[newindex];
		newentry->next = cursor;
		(ht->array)[newindex] = newentry;
		return (1);
	}
	(ht->array)[newindex] = newentry;
	return (1);
}

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: pointer to the hashtable struct.
 * @key: the key to be added to the hashtable.
 * @value: the value associated with the key.
 *
 * Return: 1 if succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *newentry;
	char *nodekey, *nodeval;
	int status;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	if (strlen(key) == 0)
		return (0);
	newentry = malloc(sizeof(hash_node_t));
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
	newentry->next = NULL;
	status = add_to_table(newentry, ht);
	return (status);
}
