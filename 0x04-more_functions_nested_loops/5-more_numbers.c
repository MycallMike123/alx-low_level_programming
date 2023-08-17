#include "main.h"

/**
 * more_numbers - Print numbers from 0 to 14, ten times
 */

void more_numbers(void)
{
	int num = 0, times;

	for (times = 0; times < 10; times++)
	{
		while (num <= 14)
		{
			if (num > 9)
			{
				_putchar((num / 10) + '0');
			}
			_putchar((num % 10) + '0');
			num++;
		}
	_putchar('\n');
	}
}
