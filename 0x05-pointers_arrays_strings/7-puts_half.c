#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: Pointer to the string to be printed
 */

void puts_half(char *str)
{
	int len = 0;
	int secstart;

	while (str[len] != '\0')
	{
		len++;
	}

	secstart = (len + 1) / 2;

	while (str[secstart] != '\0')
	{
		_putchar(str[secstart]);
		secstart++;
	}

	_putchar('\n');
}
