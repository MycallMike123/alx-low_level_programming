#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 * Return: 0 (success)
*/

int main(void)
{
	unsigned long fib1 = 0;
	unsigned long fib2 = 1;
	unsigned long next_fib;
	int i;

	for (i = 0; i < 50; i++)
	{
		next_fib = fib1 + fib2;
		printf("%lu", next_fib);


		fib1 = fib2;
		fib2 = next_fib;

		if (i == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}
