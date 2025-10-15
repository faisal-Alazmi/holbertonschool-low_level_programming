#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: address of head pointer
 * @idx: index where new node should be added (0-based)
 * @n: value to store
 *
 * Return: address of new node, or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node, *curr;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	curr = *h;
	while (curr && i < idx - 1)
	{
		curr = curr->next;
		i++;
	}

	if (curr == NULL)
		return (NULL);

	if (curr->next == NULL)
		return (add_dnodeint_end(h, n));

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->next = curr->next;
	node->prev = curr;
	curr->next->prev = node;
	curr->next = node;

	return (node);
}
