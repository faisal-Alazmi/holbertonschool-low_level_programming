#include "hash_tables.h"

/**
 * hash_djb2 - djb2 hash function
 * @str: input string (as unsigned char *)
 *
 * Return: computed hash as unsigned long int
 *
 * Description:
 * Implements the djb2 algorithm by Dan Bernstein.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return (hash);
}
