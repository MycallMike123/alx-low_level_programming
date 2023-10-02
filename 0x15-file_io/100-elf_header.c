#include "main.h"
#include <stdio.h>
#include <string.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_elf_check_info(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_error(int elf);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abiversion(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);


/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument
 * Return: 0 Success, 98 error
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int file_descriptor;
	int read_file;
	Elf64_Ehdr *header;

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open EFL file %s\n", argv[1]);
		exit(98);
	}

	header = (Elf64_Ehdr *)malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		print_error(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	read_file = read(file_descriptor, header, sizeof(Elf64_Ehdr));
	if (read_file == -1)
	{
		free(header);
		print_error(file_descriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: Not an EFL file\n", argv[1]);
		exit(98);
	}

	print_elf_check_info(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abiversion(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	print_error(file_descriptor);

	return (0);
}

/**
 * print_elf_check_info - Print info in the ELF header
 * @e_ident: Pointer to the ELF header
 */
void print_elf_check_info(unsigned char *e_ident)
{
	int a;

	for (a = 0; a < 4; a++)
	{
		if (e_ident[a] != 127 && e_ident[a] != 'E' && e_ident[a] != 'L' &&
				e_ident[a] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_entry - prints the adress of the EFL header
 * @e_entry: The address of the ELF entry point
 * @e_ident: Pointer to the ELF header
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)e_entry);
	}
	else
	{
		printf("%#lx\n", e_entry);
	}
}

/**
 * print_error - Print an error message and exit
 * @elf: The file descriptor of the ELF file
 */

void print_error(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}


/**
 * print_class - Print the ELF header class info
 * @e_ident: Pointer to the ELF header
 */

void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Invalid class\n");
			break;
	}
}

/**
 * print_version - Print the ELF header version info
 * @e_ident: Pointer to the ELF header
 */

void print_version(unsigned char *e_ident)
{
	printf(" Version: %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_abiversion - Print the ELF header ABI version
 * @e_ident: Pointer to the ELF header
 */

void print_abiversion(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_magic - Print the ELF header magic bytes
 * @e_ident: Pointer to the ELF header
 */

void print_magic(unsigned char *e_ident)
{
	int a;

	printf(" Magic: ");
	for (a = 0; a < EI_NIDENT; a++)
	{
		printf("%02x", e_ident[a]);
		if (a < EI_NIDENT - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

/**
 * print_data - Print the ELF header data encoding info
 * @e_ident: Pointer to the ELF header
 */

void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<Invalid: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_osabi - Print the ELF header OS/ABI info
 * @e_ident: Pointer to the ELF header
 */

void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD\n");
			break;
		default:
			printf("<Unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_type - Print the ELF header type info
 * @e_type: The ELF type
 * @e_ident: Pointer to the ELF header
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<Unknown: %x>\n", e_type);
	}
}
