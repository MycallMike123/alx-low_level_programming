#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 11

/**
 * main - Generates a random valid password
 *
 * Return: 0 Success
 */

int main(void)
{
	const char chars[] = "abcdefghijklmnopqrstuvwxyz";
	const char chars1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char chars2[] = "0123456789";
	char passwd[PASSWORD_LENGTH + 1];
	const char success[] = "Tada! Congrats"
	int i;

	srand(time(NULL));

	do {
		for (i = 0; i < PASSWORD_LENGTH; i++)
		{
			if (i < 10)
				passwd[i] = chars[rand() % (sizeof(chars) - 1)];
			else if (i < 20)
				passwd[i] = chars1[rand() % (sizeof(chars1) - 1)];
			else
				passwd[i] = chars2[rand() % (sizeof(chars2) - 1)];
		}

		passwd[PASSWORD_LENGTH] = '\0';

	} while (strcmp(passwd, expected) != 0);

	printf("%s\n", passwd);

	return (0);
}
