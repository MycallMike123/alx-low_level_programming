#include "main.h"
#include <stdbool.h>
#include <ctype.h>

/**
 * cap_string - Capitalizes all words of a string
 * @str: The input string
 * Return: A pointer to the capitalized string
 */

char *cap_string(char *str)
{
	bool n = true;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (n && islower(str[i]))
		{
			str[i] = toupper(str[i]);
			n = false;
		}

		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == ',' || str[i] == ';' || str[i] == '.' ||
			str[i] == '!' || str[i] == '?' || str[i] == '"' ||
			str[i] == '(' || str[i] == ')' || str[i] == '{' ||
			str[i] == '}')
		{
			n = true;
		}
		else
		{
			n = false;
		}
	}

	return (str);
}
