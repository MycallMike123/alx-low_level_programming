#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string to be appended
 *
 * Return: A pointer to the resulting string destination
 */
char *_strcat(char *dest, char *src)
{
	char *dest_pointer = dest;

	while (*dest_pointer != '\0')
	{
		dest_pointer++;
	}

	while (*src != '\0')
	{
		*dest_pointer = *src;
		dest_pointer++;
		src++;
	}

	*dest_pointer = '\0';

	return (dest);
}
