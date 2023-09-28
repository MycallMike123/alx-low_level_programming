#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1
 * @n: A pointer to the UL integer to modify
 * @index: The index of the bit
 * Return: 1 if it worked, -1 otherwise
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_isolate;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	bit_isolate = 1UL << index;

	*n |= bit_isolate; /* sets bit to 1 */

	return (1);
}
