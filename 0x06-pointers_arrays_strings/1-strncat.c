#include "main.h"

/**
 * _strncat - Concatenates two strings with a limit on bytes
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of bytes
 *
 * Return: A pointer to the resulting string destination
 */

char *_strncat(char *dest, char *src, int n)
{
	char *dest_pointer = dest;

	while (*dest_pointer != '\0')
	{
		dest_pointer++;
	}

	while (*src != '\0' && n > 0)
	{
		*dest_pointer = *src;
		dest_pointer++;
		src++;
		n--;
	}

	*dest_pointer = '\0';

	return (dest);
}
