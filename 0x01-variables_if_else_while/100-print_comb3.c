#include <stdio.h>
/**
 * main - the entry point
 * Return: 0 (Success)
 *
*/

int main(void)
{
	int number1 = 0;
	int number2;

	while (number1 < 9)
	{
		number2 = number1 + 1;

		while (number2 <= 9)
		{
			putchar(number1 + '0');
			putchar(number2 + '0');

			if (number1 < 8)
			{
				putchar(',');
				putchar(' ');
			}

			number2++;
		}

		number1++;
	}

	putchar('\n');
	return (0);
}
