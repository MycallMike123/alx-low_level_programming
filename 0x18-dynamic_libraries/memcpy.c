#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: pointer to the destination memory area
 * @src: Pointer to the source memory area
 * @n: num of bytes to copy
 * Return: A pointer to the dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
	{
		dest[a] = src[a];
	}

	return (dest);
}
