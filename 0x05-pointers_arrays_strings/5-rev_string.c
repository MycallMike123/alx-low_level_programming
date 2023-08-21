#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: Pointer to the string to be reversed
 */

void rev_string(char *s)
{
	int first = 0;
	int length = 0;
	char rev;

	while (s[length] != '\0')
	{
		length++;
	}

	length--;

	while (first < length)
	{
		rev = s[first];
		s[first] = s[length];
		s[length] = rev;

		first++;
		length--;
	}

}
