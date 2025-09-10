#include "main.h"
/**
 * helper_sqrt - finds sqrt recursively
 * @n: number
 * @i: current guess
 *
 * Return: sqrt of n, or -1 if not found
 */
int helper_sqrt(int n, int i)
{
if (i * i == n)
return (i);
if (i * i > n)
return (-1);
return (helper_sqrt(n, i + 1));
}
/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find sqrt of
 *
 * Return: natural sqrt, or -1 if not perfect square
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (helper_sqrt(n, 0));
}
