#include "hash_tables.h"

/**
 * key_index - compute the index of a key in the hash table array
 * @key: the key (as unsigned char *)
 * @size: the size of the hash table array
 *
 * Return: the index at which the key/value should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
