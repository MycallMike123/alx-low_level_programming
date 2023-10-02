#include "main.h"
#include <stdio.h>
#include <string.h>
#include <elf.h>

void print_elf_header_info(Elf64_Ehdr *elf_hr);
void print_magic(Elf64_Ehdr *elf_hr);
void print_class(Elf64_Ehdr *elf_hr);
void print_data(Elf64_Ehdr *elf_hr);
void print_error(char *message);
void print_version(Elf64_Ehdr *elf_hr);
void print_osabi(Elf64_Ehdr *elf_hr);
void print_abiversion(Elf64_Ehdr *elf_hr);
void print_type(Elf64_Ehdr *elf_hr);
void print_entry(Elf64_Ehdr *elf_hr);


/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument
 * Return: 0 Success, 98 error
 */

int main(int argc, char *argv[])
{
	int file_descriptor;
	const char *file_name;
	Elf64_Ehdr elf_hr;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	file_name = argv[1];
	file_descriptor = open(file_name, O_RDONLY);

	if (file_descriptor == -1)
	{
		print_error("Error: Can't open ELF file");
	}

	if (read(file_descriptor, &elf_hr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		close(file_descriptor);
	}

	if (memcmp(elf_hr.e_ident, ELFMAG, SELFMAG) != 0)
	{
		close(file_descriptor);
		print_error("Error: Not an ELF file");
	}

	print_elf_header_info(&elf_hr);

	close(file_descriptor);

	return (0);
}

/**
 * print_elf_header_info - Print info in the ELF header
 * @elf_hr: Pointer to the ELF header
 */

void print_elf_header_info(Elf64_Ehdr *elf_hr)
{
	print_magic(elf_hr);
	print_class(elf_hr);
	print_data(elf_hr);
	print_version(elf_hr);
	print_osabi(elf_hr);
	print_abiversion(elf_hr);
	print_type(elf_hr);
	print_entry(elf_hr);
}

/**
 * print_entry - prints the adress of the EFL header
 * @elf_hr: Pointer to the ELF header
 */

void print_entry(Elf64_Ehdr *elf_hr)
{
	printf("  Entry:               0x%lx\n", (unsigned long)elf_hr->e_entry);
}

/**
 * print_error - Print an error message and exit
 * @message: The error message to print
 */

void print_error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * print_class - Print the ELF header class info
 * @elf_hr: Pointer to the ELF header
 */

void print_class(Elf64_Ehdr *elf_hr)
{
	printf("  Class:                             ");
	switch (elf_hr->e_ident[EI_CLASS])
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
 * @elf_hr: Pointer to the ELF header
 */

void print_version(Elf64_Ehdr *elf_hr)
{
	printf("  Version:                           %d (current)\n", elf_hr->e_ident[EI_VERSION]);
}

/**
 * print_abiversion - Print the ELF header ABI version
 * @elf_hr: Pointer to the ELF header
 */

void print_abiversion(Elf64_Ehdr *elf_hr)
{
	printf("  ABI Version:                       %d\n", elf_hr->e_ident[EI_ABIVERSION]);
}

/**
 * print_magic - Print the ELF header magic bytes
 * @elf_hr: Pointer to the ELF header
 */

void print_magic(Elf64_Ehdr *elf_hr)
{
	int a;

	printf("  Magic:   ");
	for (a = 0; a < EI_NIDENT; a++)
	{
		printf("%02x", elf_hr->e_ident[a]);
		if (a < EI_NIDENT - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

/**
 * print_data - Print the ELF header data encoding info
 * @elf_hr: Pointer to the ELF header
 */

void print_data(Elf64_Ehdr *elf_hr)
{
	printf("  Data:                              ");
	switch (elf_hr->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Invalid data encoding\n");
			break;
	}
}

/**
 * print_osabi - Print the ELF header OS/ABI info
 * @elf_hr: Pointer to the ELF header
 */

void print_osabi(Elf64_Ehdr *elf_hr)
{
	printf("  OS/ABI:                            ");
	switch (elf_hr->e_ident[EI_OSABI])
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
			printf("Unknown\n");
			break;
	}
}

/**
 * print_type - Print the ELF header type info
 * @elf_hr: Pointer to the ELF header
 */

void print_type(Elf64_Ehdr *elf_hr)
{
	printf("  Type:                              ");
	switch (elf_hr->e_type)
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
			printf("Unknown\n");
			break;
	}
}
