#include "variadic_functions.h"
#include <stdio.h>
#include <string.h>

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
		if (strchr("cifs", format[a]))
		{
			printf("%s", separator);
			switch (format[a])
			{
				case 'c':
					printf("%c", va_arg(argument, int));
					break;
				case 'i':
					printf("%d", va_arg(argument, int));
					break;
				case 'f':
					printf("%f", va_arg(argument, double));
					break;
				case 's':
				{
					string = va_arg(argument, char *);
					printf("%s", string ? string : "(nil)");
					break;
				}
			}
			separator = ", ";
		}
		a++;
	}
	va_end(argument);

	printf("\n");
}
