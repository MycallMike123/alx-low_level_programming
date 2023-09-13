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
	int output;
	int (*calculation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	calculation = get_op_func(argv[2]);

	if (calculation == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	output = calculation(a + b);
	printf("%d\n", output);

	return (0);
}
