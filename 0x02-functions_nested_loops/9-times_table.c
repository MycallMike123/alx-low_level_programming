#include "main.h"

/**
 * times_table - prints the nine times table
 *
*/

void times_table(void)
{
	int row;
	int col;
	int product;

	for (row = 0; row <= 9; row++)
	{
		for (col = 0; col <= 9; col++)
		{
			product = row * col;

			if (col != 0)
				_putchar(',');

			if (product < 10 && col != 0)
			{
				_putchar(' ');
				_putchar(' ');
			}

			if (product >= 10 && product <= 81 && col != 0)

				_putchar(' ');

			if (product >= 10)
			{
				_putchar(product / 10 + '0');
				_putchar(product % 10 + '0');
			}
			else
			{
				_putchar(product + '0');
			}
		}

		_putchar('\n');
	}
}
