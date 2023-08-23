#include "main.h"

/**
 * _strncpy - Copies a string
 * @dest: The destination string
 * @src: source string to be copied
 * @n: The maximum number of characters to be copied
 * Return: A pointer to the resulting string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int k;

	for (k = 0; k < n && src[k] != '\0'; k++)
	{
		dest[k] = src[k];
	}

	while (k < n)
	{
		dest[k] = '\0';
		k++;
	}

	return (dest);
}
