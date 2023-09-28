#include "main.h"

/**
 * get_endianness - Checks the endianness
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int variable;
	char *byte_pointer = (char *)&variable;

	variable = 1;

	return (byte_pointer[0] == 1);
}
