#include <stdio>
/**
 * main - entry point of our code
 * Return: 0 (Success)
*/

int main(void)
{
	char alphabet = 'a';

	while (alphabet <= 'z')
	{
		if (alphabet != 'q' && alphabet != 'e')
			putchar(alphabet);

		alphabet++;
	}

	putchar('\n');
	return (0);
}
