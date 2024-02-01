#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	hash_table_t *ht;
	hash_node_t *cursor;
	unsigned long int index;
	const unsigned char *key = (const unsigned char*)"betty";

	ht = hash_table_create(1024);
	hash_table_set(ht, "betty", "cool");
	hash_table_set(ht, "betty", "cool");

	index = key_index(key, ht->size);
	cursor = (ht->array)[index];
	while (cursor != NULL)
	{
		printf("%s\n" ,cursor->key);
		cursor = cursor->next;
	}
	return (EXIT_SUCCESS);
}
