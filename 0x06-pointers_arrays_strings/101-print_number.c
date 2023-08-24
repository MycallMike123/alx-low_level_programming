#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 */

void print_number(int n)
{
	int div = 1;
	int number = n;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	while (number / 10 != 0)
	{
		div *= 10;
		number /= 10;
	}

	number = n;

	while (div != 0)
	{
		_putchar('0' + (number / div));
		number %= div;
		div /= 10;
	}
}
