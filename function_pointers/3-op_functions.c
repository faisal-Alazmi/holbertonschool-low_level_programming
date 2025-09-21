#include "3-calc.h"
/**
 * op_add - returns the sum of two integers
 * @a: first operand
 * @b: second operand
 *
 * Return: a + b
 */
int op_add(int a, int b)
{
return (a + b);
}
/**
 * op_sub - returns the difference of two integers
 * @a: first operand
 * @b: second operand
 *
 * Return: a - b
 */
int op_sub(int a, int b)
{
return (a - b);
}
/**
 * op_mul - returns the product of two integers
 * @a: first operand
 * @b: second operand
 *
 * Return: a * b
 */
int op_mul(int a, int b)
{
return (a * b);
}
/**
 * op_mul - returns the product of two integers
 * @a: first operand
 * @b: second operand
 *
 * Return: a * b
 */
int op_div(int a, int b)
{
return (a / b);
}
/**
 * op_div - returns the quotient of two integers
 * @a: numerator (dividend)
 * @b: denominator (divisor)
 *
 * Return: a / b
 *
 * Note: division by zero is checked in main before calling this function.
 */
int op_mod(int a, int b)
{
return (a % b);
}
