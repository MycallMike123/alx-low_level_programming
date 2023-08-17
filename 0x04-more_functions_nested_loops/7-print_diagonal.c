#include "main.h"

/**
 * print_diagonal - Draw a diagonal line in the terminal
 * @n: Number of times the character '\' should be printed
 */

void print_diagonal(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	int s = 0;
	int i;

	while (n > 0)
	{
		for (i = 0; i < s; i++)
		{
			_putchar(' ');
		}
		_putchar('\\');
		_putchar('\n');
		s++;
		n--;
	}
}
