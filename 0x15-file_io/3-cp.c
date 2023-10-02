#include <stdio.h>
#include "main.h"

#define BUFFER_SIZE 1024

int file_copy(const char *source_filename, const char *dest_filename);

/**
 * main - Copies the content of one file to another
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument (strings)
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	int res;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	res = file_copy(argv[1], argv[2]);

	switch (res)
	{
		case 1:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		case 2:
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			exit(99);
		case 3:
			dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
			exit(100);
	}

	return (0);
}

/**
 * file_copy - Copy the content of one file to another file
 * @source_filename: The name of the source file
 * @dest_filename: The name of the destination file
 * Return: 0 success
 */

int file_copy(const char *source_filename, const char *dest_filename)
{
	int file1, file2, read_bytes, bytes_written;
	char buf[BUFFER_SIZE];

	file1 = open(source_filename, O_RDONLY);
	if (file1 == -1)
		return (1);  /* if reading error */

	file2 = open(dest_filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file2 == -1)
	{
		close(file1);
		return (2);
	}

	while ((read_bytes = read(file1, buf, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file2, buf, read_bytes);
		if (bytes_written == -1 || bytes_written != read_bytes)
		{
			close(file1);
			close(file2);
			return (2);
		}
	}

	if (read_bytes == -1)
	{
		close(file1);
		close(file2);
		return (1);
	}

	if (close(file1) == -1 || close(file2) == -1)
	{
		return (3);
	}

	return (0);
}
