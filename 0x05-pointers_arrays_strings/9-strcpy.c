#include "main.h"

/**
 * _strcpy - Copies a string from src to dest
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source strg
 * Return: Pointer to the destination buffer
 */

char *_strcpy(char *dest, char *src)
{
	int b = 0;

	while (src[b] != '\0')
	{
		dest[b] = src[b];
		b++;
	}

	dest[i] = '\0';

	return (dest);
}

