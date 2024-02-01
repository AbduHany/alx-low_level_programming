#include "hash_tables.h"

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
	hash_node_t *newentry, *cursor;
	int keylen, valuelen;
	unsigned long int newindex;
	char *nodekey, *nodeval;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	if (strlen(key) == 0)
		return (0);
	keylen = strlen(key);
	valuelen = strlen(value);
	newentry = malloc(sizeof(hash_node_t));
	if (newentry == NULL)
		return (0);
	nodekey = malloc(sizeof(char) * (keylen + 1));
	if (nodekey == NULL)
	{
		free(newentry);
		return (0);
	}
	nodeval = malloc(sizeof(char) * (valuelen + 1));
	if (nodeval == NULL)
	{
		free(newentry);
		free(nodekey);
		return (0);
	}
	strcpy(nodekey, key);
	strcpy(nodeval, value);
	newentry->key = nodekey;
	newentry->value = nodeval;
	newentry->next = NULL;
	newindex = key_index((const unsigned char *)key, ht->size);
	if ((*((ht->array) + newindex)) == NULL)
		*((ht->array) + newindex) = newentry;
	else
	{
		cursor = (*((ht->array) + newindex));
		newentry->next = cursor;
		(*((ht->array) + newindex)) = newentry;
	}
	return (1);
}
