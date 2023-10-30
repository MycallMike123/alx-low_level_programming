#include "main.h"

/**
 * create_file - Creates a file
 * @filename: The name of the file to create
 * @text_content: The NULL-terminated string to write
 * Return: 1 on success, -1 otherwise
 */

int create_file(const char *filename, char *text_content)
{
	int file_descriptor, res;
	mode_t _permissions = S_IRUSR | S_IWUSR;

	if (filename == NULL)
	{
		return (-1);
	}

	file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, _permissions);

	if (file_descriptor == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		res = write(file_descriptor, text_content, strlen(text_content));
	}

	if (res == -1 || (size_t)res != strlen(text_content))
	{
		close(file_descriptor);
		return (-1);
	}
}
