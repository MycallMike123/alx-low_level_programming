#include "main.h"
#include <string.h>

/**
 * create_file - Creates a file with text content
 * @filename: The name of the file to create
 * @text_content: The NULL-terminated string to write
 * Return: 1 on success, -1 otherwise
 */

int create_file(const char *filename, char *text_content)
{
	int file_descriptor, result_to_write;
	mode_t permissions = S_IRUSR | S_IWUSR;

	if (filename == NULL)
	{
		return (-1);
	}

	file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, permissions);
	if (file_descriptor == -1)
	{
		return (-1); /* if it can't be written */
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
