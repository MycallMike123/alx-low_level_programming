#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - The entry point
 * @argc: The number of arguments to the program
 * @argv: An array of pointers to arg
 * Return: 0 always
 */

int main(int argc, char *argv[])
{
	int a, b;
	char *output;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	output = argv[2];

	if (get_op_func(output) == NULL || output[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	if ((*output == '/' && b == 0) || (*output == '%' && b == 0))
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", get_op_func(output)(a, b));

	return (0);
}
