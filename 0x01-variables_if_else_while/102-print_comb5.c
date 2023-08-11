#include <stdio.h>
/**
 * main - the entry point
 *
 * Return: 0 (success)
*/

int main(void)
{
	int first_num = 0;
	int second_num;

	while (first_num <= 98)
	{
		second_num = first_num + 1;

		while (second_num <= 99)
		{
			putchar(first_num / 10 + '0');
			putchar(first_num % 10 + '0');
			putchar(' ');
			putchar(second_num / 10 + '0');
			putchar(second_num % 10 + '0');

			if (first_num < 98)
			{
				putchar(',');
				putchar(' ');
			}

			second_num++;
		}

		first_num++;
	}

	putchar('\n');
	return (0);
}
