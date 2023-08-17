#include <stdio.h>
#include <math.h>

/**
 * main - prints the largest prime factor
 * Return: 0 Success
 */

int main(void)
{
	long num = 612852475143;
	long lpf = -1;
	long i;

	while (num % 2 == 0)
	{
		lpf = 2;
		num /= 2;
	}

	for (i = 3; i <= sqrt(num); i += 2)
	{
		while (num % i == 0)
		{
			lpf = i;
			num /= i;
		}
	}

	if (num > 2)
	{
		lpf = num;
	}

	printf("%ld\n", lpf);

	return (0);
}
