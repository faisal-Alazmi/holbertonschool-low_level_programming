#include "main.h"
/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: the integer value, or 0 if no number found
 */
int _atoi(char *s)
{
int i = 0;
int sign = 1;
int result = 0;
while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
i++;
while (s[i] == '+' || s[i] == '-')
{
if (s[i] == '-')
sign = -sign;
i++;
}
if (s[i] < '0' || s[i] > '9')
return (0);
while (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
i++;
}
return (result * sign);
}
