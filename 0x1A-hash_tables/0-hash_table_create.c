#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 * @size: size of the hash table.
 *
 * Return: pointer to the created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *created_table;
	hash_node_t *array;

	created_table = malloc(sizeof(hash_table_t));
	if (created_table == NULL)
		return (NULL);
	array = malloc(sizeof(hash_node_t) * size);
	if (array == NULL)
	{
		free(created_table);
		return (NULL);
	}
	created_table->size = size;
	created_table->array = &array;
	return (created_table);
}
