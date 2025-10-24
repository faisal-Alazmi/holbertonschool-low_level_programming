#include "hash_tables.h"

/**
 * hash_table_get - retrieve the value associated with a key
 * @ht: pointer to hash table
 * @key: key string (non-empty)
 *
 * Return: pointer to value string, or NULL if key not found / invalid args
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *node;

	if (ht == NULL || ht->array == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);

	for (node = ht->array[idx]; node != NULL; node = node->next)
		if (strcmp(node->key, key) == 0)
			return (node->value);

	return (NULL);
}
