#include "hash_tables.h"

/**
 * free_list - free a linked list of hash nodes
 * @head: head of the list
 */
static void free_list(hash_node_t *head)
{
	hash_node_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->key);
		free(head->value);
		free(head);
		head = tmp;
	}
}

/**
 * hash_table_delete - delete a hash table and free all memory
 * @ht: pointer to the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;

	if (ht == NULL || ht->array == NULL)
		return;

	for (i = 0; i < ht->size; i++)
		free_list(ht->array[i]);

	free(ht->array);
	free(ht);
}
