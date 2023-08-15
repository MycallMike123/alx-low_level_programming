#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 * Return: 0 (success)
*/

int main(void)
{
	long long int fib1 = 1;
	long long int fib2 = 2;
	long long int next_fib;

	printf("%lld, %lld, ", fib1, fib2);

	for (int i = 2; i < 50; i++)
	{
		next_fib = fib1 + fib2;
		printf("%lld", next_fib);

		if (i < 49)
		{
			printf(", ");
		}

		fib1 = fib2;
		fib2 = next_fib;
	}
	printf("\n");
	return (0);
}
