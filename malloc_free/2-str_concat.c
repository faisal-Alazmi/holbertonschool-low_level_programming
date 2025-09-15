#include <stdlib.h>
#include "main.h"
/**
 * str_concat - concatenates two strings into newly allocated memory
 * @s1: first string (treated as "" if NULL)
 * @s2: second string (treated as "" if NULL)
 *
 * Return: pointer to new "s1s2\0" string on success, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
char *cat;
unsigned int len1 = 0, len2 = 0, i, j;
if (s1)
while (s1[len1] != '\0')
len1++;
if (s2)
while (s2[len2] != '\0')
len2++;
cat = malloc((len1 + len2 + 1) * sizeof(char));
if (cat == NULL)
return (NULL);
for (i = 0; i < len1; i++)
cat[i] = s1[i];
for (j = 0; j < len2; j++)
cat[i + j] = s2[j];
cat[len1 + len2] = '\0';
return (cat);
}
