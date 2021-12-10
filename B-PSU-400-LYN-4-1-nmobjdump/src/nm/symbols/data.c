/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump--master
** File description:
** data.c
*/

#include "nm.h"

char sym_data(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    int verif = 3;
    int types[3] = { STB_GLOBAL, STB_LOCAL, STB_WEAK };
    char result[6] = { 'D', 'd', 'W', 'R', 'r', 'W' };

    if ((shdr[sym->st_shndx].sh_type == SHT_PROGBITS &&
            (shdr[sym->st_shndx].sh_flags & SHF_ALLOC)
        ) || (shdr[sym->st_shndx].sh_type == SHT_DYNAMIC)) {
        if (shdr[sym->st_shndx].sh_flags & SHF_WRITE)
            verif = 0;
        for (int i = 0; i < 3; i++) {
            if (ELF64_ST_BIND(sym->st_info) == types[i])
                return (result[i + verif]);
        }
    }

    return (0);
}