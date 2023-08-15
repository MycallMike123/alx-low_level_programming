#include "main.h"
#include <unistd.h>

/**
 * _putchar - this writes the character to stdout
 * @c: the character to print
 * Return: 1 (Success)
 * On error, -1 is returned, and errno is set
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
