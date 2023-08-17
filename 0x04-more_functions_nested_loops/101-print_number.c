#include "main.h"

/**
 * print_number - Print an integer using _putchar
 * @n: The integer to be printed
 */

void print_number(int n)
{
	int div = 1;
	int temp = n;
	int digit =0;


	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}

	while (div > 0)
	{
		digit = n / div;
		_putchar(digit + '0');
		n -= digit * div;
		div /= 10;
	}
}
