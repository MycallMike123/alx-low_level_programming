#include "variadic_functions.h"

/**
 * sum_them_all - Sums all of it parameters
 * @n: The number of parameters
 * @...: The parameters to sum
 * Return: The sum of all parameters or 0
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int a;
	int sum = 0;

	va_list argument;

	va_start(argument, n);

	if (n == 0)
	{
		return (0);
	}

	sum = 0;
	for (a = 0; a < n; a++)
	{
		sum = sum + va_arg(argument, int);
	}

	va_end(argument);

	return (sum);
}
