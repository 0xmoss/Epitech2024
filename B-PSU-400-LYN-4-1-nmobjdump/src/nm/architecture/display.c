/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump--master
** File description:
** display.c
*/

#include "nm.h"

int display(
    int ac,
    Elf64_Ehdr *elf,
    Elf64_Shdr *shdr,
    void* data,
    char* filename
)
{
    Elf64_Sym  *symTab;
    unsigned char* strtab;
    long int  size;
    int found = -1;

    for (int i = -1; ++i < elf->e_shnum;) {
        if (shdr[i].sh_type == SHT_SYMTAB) {
            strtab = data + shdr[shdr[i].sh_link].sh_offset;
            symTab = (Elf64_Sym *)((char *)elf + shdr[i].sh_offset);
            size = shdr[i].sh_size / shdr[i].sh_entsize;
            i = elf->e_shnum;
            found = 0;
        }
    }
    if (!found) {
        if (ac > 2)
            printf("\n%s:\n", filename);
        return (dump(symTab, size, shdr, strtab));
    }

    return (-1);
}