#include "main.h"
/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search
 * @accept: the string containing the bytes to match
 *
 * Return: pointer to the first matching byte in s,
 *         or NULL if no match is found
 */
char *_strpbrk(char *s, char *accept)
{
char *a;
while (*s)
{
for (a = accept; *a; a++)
{
if (*s == *a)
return (s);
}
s++;
}
return (0);
}
