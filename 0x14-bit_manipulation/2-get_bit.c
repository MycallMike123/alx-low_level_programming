#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given
 * @n: The UL integer to extract the bit from
 * @index: The index of the bit to get
 * Return: The value of the bit at the given index, -1 otherwise
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit_isolate;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	bit_isolate = 1UL << index;

	return ((n & bit_isolate) ? 1 : 0);
}
