#include "main.h"

/**
 * print_square - Print a square in the terminal
 * @size: Size of the square
 */

void print_square(int size)
{
	int i, times;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (times = 0; times < size; times++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
