#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t linked list.
 * @head: Pointer to the head node of the list.
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		if (head->str != NULL)
			free(head->str);
		free(head);
		head = tmp;
	}
}
