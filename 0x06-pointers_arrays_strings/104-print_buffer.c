#include "main.h"
#include <stdio.h>
/**
 * print_buffer - Prints the content of a buffer
 * @b: The buffer to print
 * @size: The size of the buffer
 */
void print_buffer(char *b, int size)
{
	unsigned char *ub = (unsigned char *)b;
	int k, l;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (k = 0; k < size; k += 10)
	{
		printf("%08x: ", k);

		for (l = 0; l < 10; l++)
		{
			if (k + l < size)
				printf("%02x", ub[k + l]);
			else
				printf("  ");

			if (l % 2 == 1)
				printf(" ");
		}
		for (l = 0; l < 10; l++)
		{
			if (k + l < size)
			{
				if (ub[k + l] >= 32 && ub[k + l] <= 126)
					printf("%c", ub[k + l]);
				else
					printf(".");
			}
			else
			{
				printf(" ");
			}
		}

		printf("\n");
	}
}
