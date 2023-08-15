#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: - the number
 * Return: The value of the last digit
*/

int print_last_digit(int n)
{
	int last_dig;

	if (n < 0)
		n = -n;

	last_dig = n % 10;

	_putchar(last_dig + '0');

	return (last_dig);
}
