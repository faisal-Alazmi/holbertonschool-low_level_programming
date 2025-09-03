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
int started = 0;
while (s[i] != '\0')
{
if (s[i] == '_')
sign *= -1;
else if (s[i] >= '0' && s[i] <= '9')
{
started = 1;
result = result * 10 + (s[i] - '0');
if (s[i + 1] < '0' || s[i + 1] > '9')
break;
}
else if (started)
{
break;
}
i++;
}
return (result * sign);
}
