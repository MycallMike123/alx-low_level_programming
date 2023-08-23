#include "main.h"

/**
 * string_toupper - Converts from lowercase to upper
 * @str: The input string
 * Return: A pointer to the converted string
 */

char *string_toupper(char *str)
{
	char *pointer = str;

	while (*pointer != '\0')
	{
		if (*pointer >= 'a' && *pointer <= 'z')
		{
			*pointer = *pointer - 'a' + 'A';
		}
		pointer++;
	}

	return (str);
}
