#include "main.h"

/**
 * print_alphabet_x10 - prints alphabet ten times
 * Return: 0 (Success)
*/

void print_alphabet_x10(void)
{
	char alph;
	int i;

	for (i = 0; i < 10; i++)
	{
		alph = 'a';

		while (alph <= 'z')
		{
			_putchar(alph);
			alph++;
		}

		_putchar('\n');
	}
}
