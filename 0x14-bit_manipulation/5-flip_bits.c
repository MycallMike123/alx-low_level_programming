#include "main.h"

/**
 * flip_bits - Returns the number of bits to flip
 * @n: The first UL integer
 * @m: The second UL integer
 * Return: The number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int res = n ^ m;
	unsigned int count = 0;

	while (res > 0)
	{
		if (res & 1)
		{
			count++;
		}
		res >>= 1;  /* right shift to check next bit */
	}

	return (count);
}
