/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump--master
** File description:
** shrug.c
*/

#include "nm.h"

char sym_shrug(Elf64_Sym *sym)
{
    int types[3] = { STB_GLOBAL, STB_LOCAL, STB_WEAK };
    char values[4] = { 'U', 'u', 'w', 'C' };

    if (sym->st_shndx == SHN_UNDEF) {
        for (int i = 0; i < 3; i++)
            if (ELF64_ST_BIND(sym->st_info) == types[i])
                return (values[i]);
    }
    if (sym->st_shndx == SHN_COMMON)
        return (values[3]);
    return (0);
}
