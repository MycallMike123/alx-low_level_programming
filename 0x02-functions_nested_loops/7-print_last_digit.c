#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @int: - the number
 * Return: The value of the last digit
*/

int print_last_digit(int)
{
	int last_dig;

	if (int < 0)
		int = -int;

	last_dig = int % 10;

	_putchar(last_dig + '0');

	return (last_dig);
}
