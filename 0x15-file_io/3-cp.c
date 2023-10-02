#include "main.h"
#include <stdio.h>

#define BUFFER_SIZE 1024

int file_copy(const char *source_filename, const char *dest_filename);

/**
 * main - Copies the content of one file to another
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument (strings)
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	if (file_copy(argv[1], argv[2]) != 0)
	{
		exit(99);
	}

	return (0);
}

/**
 * file_copy - Copy the contents of one file to another
 * @source_filename: The name of the source file
 * @dest_filename: The name of the destination file
 * Return: 0 success, 1 failure
 */

int copy_file(const char *source_filename, const char *dest_filename)
{
	int f1, f2, bytes_read, bytes_written;
	char buf[BUFFER_SIZE];

	f1 = open(source_filename, O_RDONLY);
	if (f1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source_filename);
		exit(98);
	}

	f2 = open(dest_filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (f2 == -1)
	{
		close(f1);
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", dest_filename);
		exit(99);
	}

	do {
		bytes_read = read(f1, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			close(f1);
			close(f2);
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source_filename);
			exit(98);
		}

		bytes_written = write(f2, buf, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close(f1);
			close(f2);
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", dest_filename);
			exit(99);
		}
	} while (bytes_read > 0);
	if (close(f1) == -1 || close(f2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", (close(f1) == -1) ? f1 : f2);
		exit(100);
	}

	return (0);
}
