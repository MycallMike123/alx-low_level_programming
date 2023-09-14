#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_all - Prints anything
 * @format: The format string
 * @...: The arguments to print
 */

void print_all(const char * const format, ...)
{
	char *separator = "", *string;
	int a = 0;

	va_list argument;

	va_start(argument, format);

	while (format && format[a])
	{
		if (format[a] == 'c')
			printf("%s%c", separator, va_arg(argument, int));
		else if (format[a] == 'i')
			printf("%s%d", separator, va_arg(argument, int));
		else if (format[a] == 'f')
			printf("%s%f", separator, va_arg(argument, double));
		else if (format[a] == 's')
		{
			string = va_arg(argument, char *);

			if (string == NULL)
				printf("%s(nil)", separator);
			else
			{
				printf("%s%s", separator, string);
			}
		}

		separator = ", ";
		a++;

	}
	va_end(argument);

	printf("\n");
}
