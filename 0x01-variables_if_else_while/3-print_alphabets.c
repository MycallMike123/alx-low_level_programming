#include <stdio.h>
/**
 * main - the entry point
 *
 * Return: 0 (Success)
*/

int main(void)
{
	char lowerc = 'a';
	char upperc = 'A';

	while (lowerc <= 'z')
	{
		putchar(lowerc);
		lowerc++;
	}

	while (upperc <= 'Z')
	{
		putchar(upperc);
		upperc++;
	}

	putchar('\');
	return (0);
}
