#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: pointer to the hash table struct.
 * @key: key of the value we're retrieving.
 *
 * Return: a string (char *) to the retrieved value.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *cursor;
        unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
        index = key_index((const unsigned char *)key, ht->size);
	if (ht->array[index] == NULL)
	{
		return (NULL);
	}
	cursor = ht->array[index];
	while (cursor != NULL)
	{
		if (strcmp(key, cursor->key) == 0)
		{
		        return (cursor->value);
		}
		cursor = cursor->next;
	}
	return (NULL);
}
