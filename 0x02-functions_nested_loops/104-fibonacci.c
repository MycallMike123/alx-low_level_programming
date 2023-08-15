#include <stdio.h>

/**
 * main -finds and prints the first 98 Fibonacci numbers
 * Return: 0 (Success)
*/

int main(void)
{
	unsigned int fib1 = 1, fib2 = 2, next_fib;
	int i;

	printf("%u, %u,", fib1, fib2);
	for (i = 2; i < 96; i++)
	{
		next_fib = fib1 + fib2;
		printf(", %u", next_fib);

		fib1 = fib2;
		fib2 = next_fib;

	}

	printf(", %u\n", fib1 + fib2);
	return (0);
}
