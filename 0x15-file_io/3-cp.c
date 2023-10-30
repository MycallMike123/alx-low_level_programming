#include "main.h"

void file_c(int file_descriptor);
char *handle_buf(char *filename);

/**
 * main - the entry point of a code that copies content
 * @argc: The number of arguments
 * @argv: An array of pointers to the arguments
 * Return: 0 always
 */

int main(int argc, char *argv[])
{
	int _start, _end, _read, _write;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = handle_buf(argv[2]);
	_start = open(argv[1], O_RDONLY);
	_read = read(_start, buf, 1024);
	_end = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (_start == -1 || _read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		_write = write(_end, buf, _read);

		if (_end == -1 || _write == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		_read = read(_start, buf, 1024);
		_end = open(argv[2], O_WRONLY | O_APPEND);

	} while (_read > 0);

	free(buf);
	file_c(_start);
	file_c(_end);

	return (0);
}

/**
 * file_c - Closes file descriptor
 * @file_descriptor: The file descriptor to be closed
 */

void file_c(int file_descriptor)
{
	int i = close(file_descriptor);

	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(100);
	}
}

/**
 * handle_buf - Allocates a buf with 1024 bytes
 * @filename: The name of the file
 * Return: A pointer to new buf
 */

char *handle_buf(char *filename)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buf);
}
