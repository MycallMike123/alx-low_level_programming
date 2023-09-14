#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_strings - Prints strings
 * @separator: The character to be printed between strings
 * @n: The number of strings
 * @...: The strings to print
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int a;
	char *string;

	va_list argument;

	va_start(argument, n);

	for (a = 0; a < n; a++)
	{
		string =  va_arg(argument, char *);

		if (string != NULL)
		{
			printf("%s", string);
		}
		else
		{
			printf("(nil)");
		}

		if (a < n - 1 && separator != NULL)
			printf("%s", separator);
	}

	va_end(argument);
	printf("\n");
}
