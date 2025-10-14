#include "lists.h"
#include <stdlib.h>

/**
 * _strlen_local - Computes the length of a C string.
 * @s: Pointer to a null-terminated string.
 *
 * Return: Length in bytes (0 if @s is NULL).
 */
static size_t _strlen_local(const char *s)
{
	size_t len = 0;

	if (!s)
		return (0);

	while (s[len])
		len++;

	return (len);
}

/**
 * _strdup_local - Duplicates a C string using malloc (no strdup).
 * @s: Pointer to the source null-terminated string.
 *
 * Return: Pointer to newly allocated copy, or NULL on failure/if @s is NULL.
 */
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
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Address of pointer to head node.
 * @str:  String to duplicate into the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node, *cur;
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
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	cur = *head;
	while (cur->next != NULL)
		cur = cur->next;

	cur->next = node;
	return (node);
}
