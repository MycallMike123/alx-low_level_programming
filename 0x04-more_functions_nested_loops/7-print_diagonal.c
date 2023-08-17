#include "main.h"

/**
 * print_diagonal - Draw a diagonal line in the terminal
 * @n: Number of times the character '\' should be printed
 */

void print_diagonal(int n)
{
	int i;
	int s;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}


	for (i = 0; i < n; i++)
	{
		for (s = 0; s < n; s++)
		{
			if (s == i)
			{
				_putchar('\\');
			}
			else if (s < i)
			{
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
