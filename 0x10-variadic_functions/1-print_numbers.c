#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers
 * @separator: The character to be printed between numbers
 * @n: The number of integers
 * @...: The integers to print
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int a;

	va_list argument;

	va_start(argument, n);

	for (a = 0; a < n; a++)
	{
		printf("%d", va_arg(argument, int));

		if (a < n - 1 && separator != NULL)
			printf("%s", separator);
	}
	va_end(argument);

	printf("\n");
}
