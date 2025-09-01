#include "main.h"
/**
 * more_numbers - prints 10 times the numbers 0..14, then newline
 */
void more_numbers(void)
{
int r, n;
for (r = 0; r < 10; r++)
{
for (n = 0; n <= 14; n++)
{
if (n >= 10)
_putchar('1');
_putchar((n % 10) + '0');
}
_putchar('\n');
}
}
