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
	index = key_index(key, ht->size);
	hash_table_set(ht, "betty", "cool");
	printf("%s\n", ht->array[index]->value);
	hash_table_set(ht, "betty", "hi");
	printf("%s\n", ht->array[index]->value);

	cursor = (ht->array)[index];
	while (cursor != NULL)
	{
		printf("%s\n" ,cursor->key);
		cursor = cursor->next;
	}
	return (EXIT_SUCCESS);
}
