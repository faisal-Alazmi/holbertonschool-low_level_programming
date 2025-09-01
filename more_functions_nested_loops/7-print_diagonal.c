#include "main.h"
/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: number of times the character '\' should be printed
 */
void print_diagonal(int n)
{
int row, sp;
if (n <= 0)
{
_putchar('\n');
return;
}
for (row = 0; row < n; row++)
{
for (sp = 0; sp < row; sp++)
_putchar(' ');
_putchar('\\');
_putchar('\n');
}
}
