#include "hash_tables.h"

/**
 * create_node - allocate and initialize a hash node
 * @key: key to duplicate
 * @value: value to duplicate
 *
 * Return: pointer to new node, or NULL on failure
 */
static hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;
	char *dup_key, *dup_val;

	if (key == NULL || *key == '\0' || value == NULL)
		return (NULL);

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);

	dup_key = strdup(key);
	dup_val = strdup(value);
	if (dup_key == NULL || dup_val == NULL)
	{
		free(dup_key);
		free(dup_val);
		free(node);
		return (NULL);
	}

	node->key = dup_key;
	node->value = dup_val;
	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - add or update a key/value pair in a hash table
 * @ht: pointer to the hash table
 * @key: non-empty key string
 * @value: value string (duplicated; can be empty)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *cur;

	if (ht == NULL || ht->array == NULL || key == NULL || *key == '\0' ||
	    value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	/* update existing key if present */
	for (cur = ht->array[idx]; cur != NULL; cur = cur->next)
	{
		if (strcmp(cur->key, key) == 0)
		{
			char *dup_val = strdup(value);

			if (dup_val == NULL)
				return (0);
			free(cur->value);
			cur->value = dup_val;
			return (1);
		}
	}

	/* insert at head (handle collision by chaining) */
	node = create_node(key, value);
	if (node == NULL)
		return (0);
	node->next = ht->array[idx];
	ht->array[idx] = node;

	return (1);
}
