#include <stdio.h>
/**
 * main - Ther entry point of our code
 * Return: 0 (Success)
*/

int main(void)
{
	int num = 0;

	while (num < 10)
	{
		putchar(num + '0');

		if (num < 9)
		{
			putchar(',');
			putchar(' ');
		}

		num++;
	}

	putchar('\n');
	return (0);
}
