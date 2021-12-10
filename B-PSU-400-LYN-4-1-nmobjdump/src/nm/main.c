/*
** EPITECH PROJECT, 2020
** nm
** File description:
** main.c
*/

#include "nm.h"

int nm(int ac, char *filename)
{
    Elf64_Ehdr *elf;
    int fd;
    long size;
    void *data = load(filename, &fd, &size);

    if (data != NULL && data != MAP_FAILED) {
        elf = (Elf64_Ehdr*)data;
        if (elf->e_ident[EI_CLASS] == ELFCLASS64)
            build(ac, data, filename, size);
        close(fd);
        if (munmap(data, size) == -1)
            printf("munmap failed\n");
    }
    return (-1);
}

int main(int ac, char **argv)
{
    if (ac > 1)
        for (int i = 1; i < ac; i++)
            return (nm(ac, argv[i]));
    printf("Usage: my_nm <file>\n");
    return (84);
}
