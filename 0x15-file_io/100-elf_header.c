#include "main.h"
#include <sys/stat.h>
#include <elf.h>
#include <sys/types.h>

void elf_c(unsigned char *e_ident);
void _class(unsigned char *e_ident);
void _vsn(unsigned char *e_ident);
void _osabi(unsigned char *e_ident);
void _entry(unsigned long int e_entry, unsigned char *e_ident);
void _close(int elf);
void _type(unsigned int e_type, unsigned char *e_ident);
void _abiversion(unsigned char *e_ident);
void _data(unsigned char *e_ident);
void _magic(unsigned char *e_ident);

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument
 * Return: 0 Success, 98 error
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *h;
	int _read, _open;

	_open = open(argv[1], O_RDONLY);

	if (_open == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	h = malloc(sizeof(Elf64_Ehdr));
	if (h == NULL)
	{
		_close(_open);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	_read = read(_open, h, sizeof(Elf64_Ehdr));

	if (_read == -1)
	{
		free(h);
		_close(_open);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	elf_c(h->e_ident);
	printf("ELF Header:\n");
	_magic(h->e_ident);
	_class(h->e_ident);
	_data(h->e_ident);
	_vsn(h->e_ident);
	_osabi(h->e_ident);
	_abiversion(h->e_ident);
	_type(h->e_type, h->e_ident);
	_entry(h->e_entry, h->e_ident);

	free(h);
	_close(_open);
	return (0);
}

/**
 * elf_c - Print info in the ELF header
 * @e_ident: Pointer to the ELF header
 */

void elf_c(unsigned char *e_ident)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (e_ident[idx] != 127 && e_ident[idx] != 'E' &&
				e_ident[idx] != 'L' && e_ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * _class - Print the ELF header class info
 * @e_ident: Pointer to the ELF header
 */

void _class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;

		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * _vsn - Print the ELF header version info
 * @e_ident: Pointer to the ELF header
 */

void _vsn(unsigned char *e_ident)
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
 * _osabi - Print the ELF header OS/ABI info
 * @e_ident: Pointer to the ELF header
 */

void _osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
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
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * _entry - prints the adress of the EFL header
 * @e_entry: The address of the ELF entry point
 * @e_ident: Pointer to the ELF header
 */

void _entry(unsigned long int e_entry, unsigned char *e_ident)
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
 * _close - Print an error message and exit
 * @elf: The file descriptor of the ELF file
 */

void _close(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * _type - Print the ELF header type info
 * @e_type: The ELF type
 * @e_ident: Pointer to the ELF header
 */

void _type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type >>= 8;
	}

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
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * _abiversion - Print the ELF header ABI version
 * @e_ident: Pointer to the ELF header
 */

void _abiversion(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * _data - Print the ELF header data encoding info
 * @e_ident: Pointer to the ELF header
 */

void _data(unsigned char *e_ident)
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
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * _magic - Print the ELF header magic bytes
 * @e_ident: Pointer to the ELF header
 */

void _magic(unsigned char *e_ident)
{
	int idx;

	printf(" Magic: ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", e_ident[idx]);

		if (idx == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}

}

