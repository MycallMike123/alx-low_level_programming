#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of strings
 * Return: 0 Success,1 error
 */

int main(int argc, char *argv[])
{
	int cents, coins_number, coin_count, a;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	coins_number = sizeof(coins) / sizeof(coins[0]);
	coin_count = 0;

	for (a = 0; a < coins_number; a++)
	{
		while (cents >= coins[a])
		{
			cents -= coins[a];
			coin_count++;
		}
	}

	printf("%d\n", coin_count);

	return (0);
}
