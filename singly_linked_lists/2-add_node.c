#include "lists.h"
#include <stdlib.h>

/* Helpers (محلية داخل هذا الملف فقط) */
static size_t _strlen_local(const char *s)
{
	size_t len = 0;

	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

static char *_strdup_local(const char *s)
{
	size_t i, len;
	char *p;

	if (!s)
		return (NULL);

	len = _strlen_local(s);
	p = malloc(len + 1);
	if (!p)
		return (NULL);

	for (i = 0; i < len; i++)
		p[i] = s[i];
	p[len] = '\0';
	return (p);
}

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Address of the pointer to the head node.
 * @str:  String to duplicate into the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *node;
	char *dup;
	unsigned int len;

	if (head == NULL || str == NULL)
		return (NULL);

	dup = _strdup_local(str);
	if (dup == NULL)
		return (NULL);

	len = (unsigned int)_strlen_local(dup);

	node = malloc(sizeof(*node));
	if (node == NULL)
	{
		free(dup);
		return (NULL);
	}

	node->str = dup;
	node->len = len;
	node->next = *head;
	*head = node;

	return (node);
}
