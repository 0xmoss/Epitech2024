/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump--master
** File description:
** elf.c
*/

#include "nm.h"

int elf(Elf64_Ehdr *elf, char *path)
{
    char **data = phase_split(path, '/', EMPTY, NULL);
    char *binary = data[phase_llength(data, NULL) - 1];

    if (elf->e_ident[EI_MAG0] != 0x7f ||
        elf->e_ident[EI_MAG1] != 'E' ||
        elf->e_ident[EI_MAG2] != 'L' ||
        elf->e_ident[EI_MAG3] != 'F' ||
        (elf->e_type != 1 &&
        elf->e_type != 2 &&
        elf->e_type != 3)) {
        printf("%s: %s: File format not recognized\n", binary, path);
        return (-1);
    }
    return (1);
}