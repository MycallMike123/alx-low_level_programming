#include "main.h"

/**
 * print_triangle - Print a triangle
 * @size: Size of the triangle
 */

void print_triangle(int size)
{
	int row, space, hashtag;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 1; row <= size; row++)
	{
		for (space = 1; space <= size - row; space++)
		{
			_putchar(' ');
		}
		for (hashtag = 1; hashtag <= row; hashtag++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
