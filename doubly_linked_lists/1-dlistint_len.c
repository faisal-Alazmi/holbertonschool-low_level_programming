#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a dlistint_t list
 * @h: head pointer
 *
 * Return: list length
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}
