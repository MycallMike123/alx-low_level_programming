#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a random valid password
 *
 * Return: 0 Success
 */

int main(void)
{
	int passwd[100];
	int a;
	int all;
	int n;

	all = 0;

	srand(time(NULL));

	for (a = 0; a < 100; a++)
	{
		passwd[a] = rand() % 78;
		all += (passwd[a] + '0');
		putchar(passwd[a] + '0');
		if ((2772 - all) - '0' < 78)
		{
			n = 2772 - all - '0';
			all += n;
			putchar(n + '0');
			break;
		}

	}

	return (0);
}
