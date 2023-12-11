#include <stdio.h>

/**
 * add - a function that adds a and b
 * @a: the first digit
 * @b: the second digit
 * Return: Sum
 */

int add(int a, int b)
{
	return (a + b);
}

/**
 * mul - multiplies a and b
 * @a: the first digit
 * @b: the second digit
 * Return: Multiple
 */

int mul(int a, int b)
{
	return (a * b);
}

/**
 * sub - substacts a minus b
 * @a: the first digit
 * @b: the second digit
 * Return: Difference
 */

int sub(int a, int b)
{
	return (a - b);
}

/**
 * div - Returns division
 * @a: the first digit
 * @b: the second digit
 * Return: Quotient
 */

int div(int a, int b)
{
	if (b == 0)
	{
		return (0);
	}
	return (a / b);
}

/**
 * mod - Returns the remainder
 * @a: the first digit
 * @b: the second digit
 * Return: The remainder
 */

int mod(int a, int b)
{
	if (b == 0)
	{
		return (0);
	}
	return (a % b);
}
