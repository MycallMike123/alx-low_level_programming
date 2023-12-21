#include "hash_tables.h"

/**
 * hash_djb2 - Hash function using the djb2 algorithm
 * @str: The input string
 * Return: The hash value
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	int c;
	unsigned long int hash = 5381;

	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return (hash);
}
