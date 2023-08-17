#include <stdio.h>

/**
 * main - prints Fizz, Buzz, or FizzBuzz
 * Return: 0 success
 */

int main(void)
{
	int num;

	for (num = 1; num <= 100; num++)
	{

		if (num % 3 == 0)
		{
			printf("Fizz ");
		}

		else if (num % 5 == 0)
		{
			printf("Buzz ");
		}
		else if (num % 3 == 0 && num % 5 == 0)
		{
			printf("FizzBuzz ");
		}
		else
		{
			printf("%d ", num);
		}

	}
	printf("\n");

	return (0);
}
