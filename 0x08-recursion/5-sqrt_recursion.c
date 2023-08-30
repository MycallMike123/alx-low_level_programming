#include "main.h"

/**
 * _sqrt_recursion - Calculates the natural square root
 * @n: The number to calculate the square root
 * Return: The natural square root of n or -1
 */
int _sqrt_recursion(int n)
{
	if (n == 0 || n == 1)
	{
		return (n);
	}

	if (n < 0)
	{
		return (-1);
	}

	return (_sqrt_recursion(n, 1, n));
}
