#include "main.h"
#include <limits.h>
/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: the integer value, or 0 if no number found
 *
 * Behavior (Holberton-style):
 * - Scan from start; before the first digit:
 *   every '-' flips the sign, '+' is ignored, other chars are ignored.
 * - Once the first digit appears, parse contiguous digits then stop.
 * - If no digits at all, return 0.
 * - Handle INT_MAX/INT_MIN without signed overflow.
 */
int _atoi(char *s)
{
int i = 0;
int sign = 1;
int result = 0;
int started = 0;
while (s[i] != '\0' && !started)
{
if (s[i] == '-')
sign = -sign;
else if (s[i] >= '0' && s[i] <= '9')
started = 1;
i++;
}
if (!started)
return (0);
i--;
if (sign == 1)
{
while (s[i] >= '0' && s[i] <= '9')
{
int d = s[i] - '0';
if (result > (INT_MAX - d) / 10)
return (INT_MAX);
result = result * 10 + d;
i++;
}
return (result);
}
else
{
while (s[i] >= '0' && s[i] <= '9')
{
int d = s[i] - '0';
if (result < (INT_MIN + d) / 10)
return (INT_MIN);
result = result * 10 - d;
i++;
}
return (result);
}
}
