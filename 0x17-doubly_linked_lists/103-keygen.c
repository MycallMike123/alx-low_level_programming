#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments taken to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 Success
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char password[7], *xcd;
	int length = strlen(argv[1]), a, tmp;

	xcd = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	tmp = (length ^ 59) & 63;
	password[0] = xcd[tmp];

	tmp = 0;
	for (a = 0; a < length; a++)
		tmp += argv[1][a];
	password[1] = xcd[(tmp ^ 79) & 63];

	tmp = 1;
	for (a = 0; a < length; a++)
		tmp *= argv[1][a];
	password[2] = xcd[(tmp ^ 85) & 63];

	tmp = 0;
	for (a = 0; a < length; a++)
	{
		if (argv[1][a] > tmp)
			tmp = argv[1][a];
	}
	srand(tmp ^ 14);
	password[3] = xcd[rand() & 63];

	tmp = 0;
	for (a = 0; a < length; a++)
		tmp += (argv[1][a] * argv[1][a]);
	password[4] = xcd[(tmp ^ 239) & 63];

	for (a = 0; a < argv[1][0]; a++)
		tmp = rand();
	password[5] = xcd[(tmp ^ 229) & 63];

	password[6] = '\0';
	printf("%s", password);
	return (0);
}
