/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump--master
** File description:
** truncated.c
*/

#include "nm.h"

int trucated(
    Elf64_Ehdr *elf,
    Elf64_Shdr *shdr,
    long size
)
{
    unsigned long data = elf->e_shnum * elf->e_shentsize + elf->e_shoff;

    if (data > (unsigned long)size)
        return (-1);
    for (size_t i = 0; i < elf->e_shnum; i++) {
        if (selection(shdr, i)) {
            data = shdr[i].sh_size + shdr[i].sh_offset;
            if (data > (unsigned long)size)
                return (-2);
        }
    }

    return (0);
}
