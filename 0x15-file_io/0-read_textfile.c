#include "main.h"

/**
 * read_textfile - Reads and prints the contents of a text file
 * @filename: The name of the file to read
 * @letters: number of letters read and print
 * Return: The actual number of letters that are read and printed, 0 otherwise
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	char *letters_bytes;
	ssize_t bytes_read, bytes_written;

	if (filename == NULL)
		return (0); /* if file is NULL */

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1) /* file can't be opened */
		return (0);

	letters_b = malloc(letters);
	if (letters_b == NULL)  /* if memory allocation fails */
	{
		close(file_descriptor);
		return (0);
	}

	bytes_read = read(file_descriptor, letters_b, letters);
	if (bytes_read == -1)
	{
		close(file_descriptor);
		free(letters_b);
		return (0);  /** if  reading fails */
	}

	bytes_written = write(STDOUT_FILENO, letters_b, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		close(file_descriptor);
		free(letters_b);
		return (0);  /* if stdout fails */
	}

	close(file_descriptor);
	free(letters_b);
	return (bytes_written);
}
