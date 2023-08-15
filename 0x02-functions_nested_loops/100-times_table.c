#include "main.h"
/**
 * print_times_table - Prints the n times table, starting with 0
 * @n: The value up to which the times table should be printed.
*/
void print_times_table(int n)
{
	int row, col, result;

	if (n >= 0 && n <= 15)
	{
		for (row = 0; row <= n; row++)
		{
			for (col = 0; col <= n; col++)
			{
				result = row * col;
				if (col != 0)
				{
					_putchar(',');
					_putchar(' ');
				}
				if (result < 10)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
				else if (result >= 10 && result <= 99)
					_putchar(' ');
					_putchar(' ');
				else
					_putchar(' ');
				}
				if (result >= 100)
				{
					_putchar(result / 100 + '0');
					_putchar(result / 10 + '0');
					_putchar(result % 10 + '0');
				else if (result >= 10)
					_putchar(result / 10 + '0');
					_putchar(result % 10 + '0');
				}
			}
		_putchar('\n');
		}
	}
}
