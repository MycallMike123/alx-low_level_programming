#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0
 * @n: A pointer to the UL integer to modify
 * @index: The index of the bit to set
 * Return: 1 if it worked, -1 othersise
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_isolate;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	bit_isolate = 1UL << index;
	*n &= ~mask; /* Clears the bit to 0 */

	return (1);
}
