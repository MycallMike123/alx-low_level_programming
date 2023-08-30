#include "main.h"

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = string_len(s);

	return (_palindrome(s, 0, len - 1));
}

/**
 * _palindrome - function to check if a string is a palindrome
 * @s: The string to check
 * @srt: The starting index for comparison
 * @end: The ending index for comparison
 * Return: 1 if s is a palindrome, 0 otherwise
 */

int _palindrome(char *s, int srt, int end)
{
	if (srt >= end)
	{
		return (1);
	}

	if (s[srt] != s[end])
	{
		return (0);
	}
	return (_palindrome(s, srt + 1, end - 1));
}

/**
 * string_len - Calculates the length of a string
 * @s: The string to check
 * Return: The length of the string
 */
int string_len(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
