#include "main.h"

/**
 * factorial - prints the factorial
 * @n: the number to calculate the factorial
 * Return: The factorial of n, or -1 if n is negative
 */
int factorial(int n)
{
	if (n == 0)
	{
		return (1);
	}

	if (n < 0)
	{
		return (-1);
	}

	return (n * factorial(n - 1));
}
