#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 * Return: 0 (success)
*/

int main(void)
{
	int fib1 = 1;
	int fib2 = 2;
	int next_fib;
	int i;

	printf("%d, %d", fib1, fib2);

	for (i = 2; i < 48; i++)
	{
		next_fib = fib1 + fib2;
		printf(", %d", next_fib);


		fib1 = fib2;
		fib2 = next_fib;
	}
	printf("\n");
	return (0);
}
