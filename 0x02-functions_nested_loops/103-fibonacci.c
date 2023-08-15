#include <stdio.h>

/**
 * main -finds and prints the sum of the even-valued terms
 * Return: 0 (Success)
*/
int main(void)
{
	int one = 1;
	int two = 2;
	int next = one + two;
	int sum = 2;

	while (next <= 4000000)
	{
		if (next % 2 == 0)
		{
			sum += next;
		}
		one = two;
		two = next;
		next = one + two;
	}
	printf("%d\n", sum);

	return (0);
}
