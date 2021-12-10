/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump--master
** File description:
** code.c
*/

#include "nm.h"

char sym_code(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    int types[3] = { STB_GLOBAL, STB_LOCAL, STB_WEAK };
    char result[3] = { 'T', 't', 'W' };

    if (ELF64_ST_TYPE(sym->st_info) == STT_FUNC &&
        shdr[sym->st_shndx].sh_type == SHT_PROGBITS &&
        (shdr[sym->st_shndx].sh_flags & SHF_EXECINSTR) &&
        (shdr[sym->st_shndx].sh_flags & SHF_ALLOC)) {
            for (int i = 0; i < 3; i++)
                if (ELF64_ST_BIND(sym->st_info) == types[i])
                    return (result[i]);
    }

    return (0);
}