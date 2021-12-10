/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump--master
** File description:
** sym_array.c
*/

#include "nm.h"

char sym_array(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    int types[3] = { STB_GLOBAL, STB_LOCAL, STB_WEAK };
    char result[4] = { 'T', 't', 'W', '?' };

    if ((ELF64_ST_TYPE(sym->st_info) == STT_OBJECT ||
        ELF64_ST_TYPE(sym->st_info) == STT_NOTYPE) &&
        (shdr[sym->st_shndx].sh_flags & SHF_WRITE) &&
        (shdr[sym->st_shndx].sh_flags & SHF_ALLOC)) {
            for (int i = 0; i < 3; i++)
                if (ELF64_ST_BIND(sym->st_info) == types[i])
                    return (result[i]);
    }

    return (result[3]);
}