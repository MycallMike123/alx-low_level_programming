#include "main.h"

/**
 * print_line - Draw a straight line in the terminal
 * @n: Number of times
 */

void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	while (n > 0)
	{
		_putchar('_');
		n--;
	}
	_putchar('\n');
}
