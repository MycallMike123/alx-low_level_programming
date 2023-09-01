#include "main.h"
#include <stdio.h>

/**
 * main - prints its name
 * @argc: number of command line arguments
 * @argv: An array of strings containing the command-line
 * Return: 0 success
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}
