#include "main.h"

/**
 * get_bit - Gets the value of a bit in a given idx
 * @n: The UL integer to extract the bit from
 * @index: The index of the bit to get
 * Return: The value of the bit, -1 otherwise
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int m;


	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	m = 1UL << index;

	return ((n & m) ? 1 : 0);
}
