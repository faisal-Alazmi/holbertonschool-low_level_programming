#include "hash_tables.h"

/**
 * hash_table_print - print a hash table as {'key': 'value', ...}
 * @ht: pointer to the hash table
 *
 * Description: prints key/value pairs in the order of the array,
 * then list order within each bucket. Prints nothing if @ht is NULL.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int first = 1;
	hash_node_t *node;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		for (node = ht->array[i]; node != NULL; node = node->next)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			first = 0;
		}
	}
	printf("}\n");
}
