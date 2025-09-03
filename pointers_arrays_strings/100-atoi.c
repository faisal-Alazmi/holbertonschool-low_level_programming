#include "main.h"
#include <limits.h>
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
int digit;
int found_digit = 0;
while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
i++;
while (s[i] == '+' || s[i] == '-')
{
if (s[i] == '-')
sign = -sign;
i++;
}
while (s[i] >= '0' && s[i] <= '9')
{
found_digit = 1;
digit = s[i] - '0';
if (sign == 1)
{
if (result > (INT_MAX - digit) / 10)
return INT_MAX;
}
else
{
if (-result < (INT_MIN + digit) / 10)
return INT_MIN; 
}
result = result * 10 + digit;
i++;
}
if (!found_digit)
return 0;
return result * sign;
}
