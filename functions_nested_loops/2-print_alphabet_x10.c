#include "main.h"
/**
 * print_alphabet_x10 - prints 10 times the alphabet in lowercase
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
    int i;
    char c;

    for (i = 0; i < 10; i++) /* كرر 10 مرات */
    {
        for (c = 'a'; c <= 'z'; c++) /* من a إلى z */
        {
            _putchar(c);
        }
        _putchar('\n'); /* سطر جديد بعد كل أبجدية */
    }
}
