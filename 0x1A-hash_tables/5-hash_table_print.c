#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: pointer to the hash table struct.
 *
 * Return: void.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int tablesize, i, last_node;
	hash_node_t *cursor;

	tablesize = ht->size;
	for (i = 0, last_node = 0; i < tablesize; i++)
	{
		if (ht->array[i])
			last_node = i;
	}
	if (ht == NULL)
		return;
	printf("{");
	for (i = 0; i < tablesize; i++)
	{
		if (ht->array[i])
		{
			cursor = ht->array[i];
			while (cursor != NULL)
			{
				printf("\'%s\': \'%s\'", cursor->key, cursor->value);
				if (cursor != NULL && i != last_node)
					printf(", ");
				cursor = cursor->next;
			}
		}
	}
	printf("}\n");
}
