#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Prints a name
 * @name: name to be printed
 * @f: A pointer to the function being printing
 */
void print_name(char *name, void (*f)(char *))
{
	if (f != NULL && name != NULL)
	{
		f(name);
	}
}
