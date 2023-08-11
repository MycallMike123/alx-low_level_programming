#include <stdio.h>
/**
 * main - the entry point or our main fn
 * Return: 0 (Success)
*/

int main(void)
{
	int first_num = 0;
	int second_num;
	int third_num;

	while (first_num <= 7)
	{
		second_num = first_num + 1;

		while (second_num <= 8)
		{
			third_num = second_num + 1;

			while (third_num <= 9)
			{
				putchar(first_num + '0');
				putchar(second_num + '0');
				putchar(third_num + '0');

				if (first_num < 7)
				{
					putchar(',');
					putchar(' ');
				}

				third_num++;
			}

			second_num++;
		}

		first_num++;
	}

	putchar('\n');
	return (0);
}
