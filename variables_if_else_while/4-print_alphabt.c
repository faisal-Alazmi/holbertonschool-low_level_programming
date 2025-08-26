#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase except q and e,
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char ch;
for (ch = 'a'; ch <= 'z'; ch++)
{
if (ch != 'q' && ch != 'e')
putchar(ch);
}
putchar('\n');
return (0);
}
