#include "main.h"

/**
 * get_endianness - Checks the endianness of the systm
 * Return: 0 big, 1 small endian
 */

int get_endianness(void)
{
	unsigned int val = 1;
	char *pointer = (char *)&val;

	return (pointer[0] == 1);
}
