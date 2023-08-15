#include <stdio.h>

/**
 * main -finds and prints the first 98 Fibonacci numbers
 * Return: 0 (Success)
*/

int main(void)
{
	int fib1 = 1, fib2 = 2, next_fib;

	printf("%d, %d, ", fib1, fib2);
	for (int i = 2; i < 98; i++)
	{
		next_fib = fib1 + fib2;
		printf("%d", next_fib);

		if (i != 97)
		{
			printf(", ");
		}

		fib1 = fib2;
		fib2 = next_fib;

	}

	printf("\n");
	return (0);
}
