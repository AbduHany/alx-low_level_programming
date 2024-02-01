#include "hash_tables.h"

/**
 * key_index - gives you the index of a key.
 * @key: char * to key string.
 * @size: size of the array of the hash table.
 *
 * Return: the index/bucket to where the element will
 * be placed in the hash table.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hashcode, index;

	hashcode = hash_djb2(key);
	index = hashcode % size;
	return (index);
}
