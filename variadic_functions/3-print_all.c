#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_all - prints anything based on a format string
 * @format: list of argument types ('c' char, 'i' int, 'f' float, 's' string)
 *
 * Description: other chars in format are ignored.
 * Prints a newline at the end.
 * Uses at most 1 while loop and 1 if (for NULL strings).
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
va_list ap;
unsigned int i = 0;
char *s;
char *sep = "";
va_start(ap, format);
while (format && format[i])
{
switch (format[i])
{
case 'c':
printf("%s%c", sep, va_arg(ap, int));
sep = ", ";
break;
case 'i':
printf("%s%d", sep, va_arg(ap, int));
sep = ", ";
break;
case 'f':
printf("%s%f", sep, va_arg(ap, double));
sep = ", ";
break;
case 's':
s = va_arg(ap, char *);
if (s == NULL)
s = "(nil)";
printf("%s%s", sep, s);
sep = ", ";
break;
default:
break;
}
i++;
}
printf("\n");
va_end(ap);
}
