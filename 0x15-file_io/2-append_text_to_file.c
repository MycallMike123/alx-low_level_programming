#include "main.h"
#include <string.h>

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: The name of the file to append
 * @text_content: The NULL-terminated string to add
 * Return: 1 on success, -1 otherwise
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, res;

	if (filename == NULL)
	{
		return (-1);
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		res = write(file_descriptor, text_content, strlen(text_content));

		if (res == -1 || (size_t)res != strlen(text_content))
		{
			close(file_descriptor);
			return (-1);
		}

	}

	close(file_descriptor);
	return (1);
}
