#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 * @ht: the pointer the hash table struct.
 *
 * Return: void.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int tablesize, i;
	hash_node_t *cursor, *cursor2;

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
				printf("deleting key: %s deleting value: %s\n", cursor->key, cursor->value);
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
