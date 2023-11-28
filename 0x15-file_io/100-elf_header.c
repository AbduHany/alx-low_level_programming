#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


/**
 * checkifelf - checks if the file has elf magic numbers.
 * @e_ident: array of elf magic numbers at elf header.
 * Return: void.
 */
void checkifelf(unsigned char *e_ident)
{
	int flag = 0;

	if (e_ident[EI_MAG0] == 127 && e_ident[EI_MAG1] == 69 &&
	e_ident[EI_MAG2] == 76 && e_ident[EI_MAG3] == 70)
	{
		flag = 1;
	}

	if (flag == 0)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * printmagic - prints the elf magic numbers in the header.
 * @e_ident: array of elf magic numbers at elf header.
 * Return: void
 */
void printmagic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		if (i == EI_NIDENT - 1)
		{
			printf("%02x\n", e_ident[i]);
			continue;
		}
		printf("%02x ", e_ident[i]);
	}
}

/**
 * printclass - prints the class of an elf header.
 * @e_ident: pointer to array containing elf class.
 * Return: void.
 */
void printclass(unsigned char *e_ident)
{
	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

/**
 * printdata - prints the data encoding of the
 * processor-specific data in the elf file.
 * @e_ident: pointer to array containing elf class.
 * Return: void.
 */
void printdata(unsigned char *e_ident)
{
	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATANONE)
		printf("none\n");
	else if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

/**
 * printversion - prints the version of elf file
 * in the header.
 * @e_ident: pointer to array containing elf version.
 * Return: void.
 */
void printversion(unsigned char *e_ident)
{
	printf("  Version:                           ");
	if (e_ident[EI_VERSION] == EV_CURRENT)
	{
		printf("%d (current)\n", e_ident[EI_VERSION]);
	}
	else
		printf("%d\n", e_ident[EI_VERSION]);
}

/**
 * printOSABI - operating system and
 * ABI (Application Binary Interface) for elf file.
 * @e_ident: pointer to array contining elf OSABI.
 * Return: void.
 */
void printOSABI(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	if (e_ident[EI_OSABI] == ELFOSABI_NONE)
		printf("UNIX - System V\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}

/**
 * printABIVER - prints ABI version of ELF file.
 * @e_ident: pointer to array containing elf
 * ABI version.
 * Return: void.
 */
void printABIVER(unsigned char *e_ident)
{
	printf("  ABI Version:                       ");
	printf("%d\n", e_ident[EI_ABIVERSION]);
}

/**
 * printtype - prints the type of elf file.
 * @e_type: member that identifies the elf
 * file type.
 * @e_ident: pointer to array containing elf
 * identifiers.
 * Return: void.
 */
void printtype(unsigned int e_type, unsigned char *e_ident)
{
	printf("  Type:                              ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type = e_type >> 8;

	if (e_type == ET_NONE)
		printf("NONE (None)\n");
	else if (e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (e_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", e_type);
}

/**
 * printentry - prints virtual address to
 * which the system first transfers control
 * starting the process.
 * @e_entry: member that identifies entry
 * address.
 * @e_ident: pointer to array containing elf
 * identifiers.
 * Return: void.
 */
void printentry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = __builtin_bswap64(e_entry);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("0x%x\n", (unsigned int)e_entry);
	else
		printf("0x%lx\n", e_entry);
}

/**
 * closeelf - closes an elf file.
 * @elffile: FD for the elf file.
 * Return: void.
 */
void closeelf(int elffile)
{
	if (close(elffile) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close elf file %d\n", elffile);
		exit(98);
	}
}

/**
 * main - prints the header of an elf file.
 * @argc: number of arguments.
 * @argv: pointer to string array of arguments.
 *
 * Return: 0 if success.
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	int fd_open, fd_read;
	Elf64_Ehdr *ptr;

	fd_open = open(argv[1], O_RDONLY);
	if (fd_open == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	ptr = malloc(sizeof(Elf64_Ehdr));
	if (ptr == NULL)
	{
		close(fd_open);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	fd_read = read(fd_open, ptr, sizeof(Elf64_Ehdr));
	if (fd_read == -1)
	{
		free(ptr);
		close(fd_open);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	checkifelf(ptr->e_ident);
	printf("ELF Header:\n");
	printmagic(ptr->e_ident);
	printclass(ptr->e_ident);
	printdata(ptr->e_ident);
	printversion(ptr->e_ident);
	printOSABI(ptr->e_ident);
	printABIVER(ptr->e_ident);
	printtype(ptr->e_type, ptr->e_ident);
	printentry(ptr->e_entry, ptr->e_ident);

	free(ptr);
	closeelf(fd_open);
	return (0);
}
