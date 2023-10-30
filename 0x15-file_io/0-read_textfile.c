#include "main.h"

/**
 * read_textfile - Reads and prints the contents of a text file
 * @filename: The name of the file to read
 * @letters: The number of letters to print and read
 * Return: The actual number of letters read and printed, 0 otherwise
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	char *letters_buffer;
	ssize_t bytes_read, bytes_written;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	letters_buffer = malloc(letters);

	if (letters_buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}

	bytes_read = read(file_descriptor, letters_buffer, letters);

	if (bytes_read == -1)
	{
		close(file_descriptor);
		free(letters_buffer);
		return (0);  /** if  reading fails */
	}

	bytes_written = write(STDOUT_FILENO, letters_buffer, bytes_read);

	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		close(file_descriptor);
		free(letters_buffer);
		return (0);
	}
	close(file_descriptor);
	free(letters_buffer);
	return (bytes_written);
}
