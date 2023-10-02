#include "main.h"
#include <string.h>

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: The name of the file to append to
 * @text_content: The NULL-terminated string to add
 * Return: 1 on success, -1 otherwise
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, result_to_write;

	if (filename == NULL)
	{
		return (-1);
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
	{
		return (-1); /* if it can't be opened */
	}

	if (text_content != NULL)
	{
		result_to_write = write(file_descriptor, text_content, strlen(text_content));
		if (result_to_write == -1 || (size_t)result_to_write != strlen(text_content))
		{
			close(file_descriptor);
			return (-1);  /* if it fails to write */
		}
	}

	close(file_descriptor);
	return (1);
}
