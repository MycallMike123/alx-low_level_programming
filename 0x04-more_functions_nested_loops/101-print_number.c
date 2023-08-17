#include "main.h"

/**
 * print_number - Print an integer using _putchar
 * @n: The integer to be printed
 */

void print_number(int n)
{
	unsigned int temp = n;

	if (n < 0)
	{
		_putchar('-');
		temp = -temp;
	}

	if ((temp / 10) > 0)
	{
		print_number(temp / 10);
	}

	_putchar((temp % 10) + '0');
}
