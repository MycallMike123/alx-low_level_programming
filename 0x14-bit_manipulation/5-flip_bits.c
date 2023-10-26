#include "main.h"

/**
 * flip_bits - Returns the number of bits to flip
 * @n: The first UL integer
 * @m: The second UL integer
 * Return: The number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_res = n ^ m;
	unsigned int cnt = 0;

	while (xor_res > 0)
	{
		if (xor_res & 1)
		{
			cnt++;
		}

		xor_res >>= 1;
	}

	return (cnt);
}
