#include <stddef.h>
#include "function_pointers.h"
/**
 * int_index - searches for an integer using a comparison function
 * @array: array of integers
 * @size: number of elements in the array
 * @cmp: pointer to a function used to compare values
 *
 * Return: index of the first element for which cmp does not return 0,
 *         -1 if no element matches or if size <= 0,
 *         -1 if array or cmp is NULL.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
int i;
if (array == NULL || cmp == NULL || size <= 0)
return (-1);
for (i = 0; i < size; i++)
{
if (cmp(array[i]) != 0)
return (i);
}
return (-1);
}
