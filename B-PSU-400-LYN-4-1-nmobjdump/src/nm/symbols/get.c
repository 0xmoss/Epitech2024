/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump--master
** File description:
** nm64_sym.c
*/

#include "nm.h"

char sym_get(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    int types[3] = { STB_GLOBAL, STB_LOCAL, STB_WEAK };
    char result[5] = { 'A', 'V', 'B', 'b', 'W' };
    char ret = sym_shrug(sym);

    if (ret == 0) {
        if (sym->st_shndx == SHN_ABS)
            return (result[0]);
        if (ELF64_ST_TYPE(sym->st_info) == STT_OBJECT &&
            ELF64_ST_BIND(sym->st_info) == STB_WEAK)
            return (result[1]);
        if (shdr[sym->st_shndx].sh_type == SHT_NOBITS) {
            for (int i = 0; i < 3; i++)
                if (ELF64_ST_BIND(sym->st_info) == types[i])
                    return (result[i + 2]);
        }
        ret = sym_code(sym, shdr);
        if (ret != 0)
            return (ret);
        ret = sym_data(sym, shdr);
        if (ret != 0)
            return (ret);
        return (sym_array(sym, shdr));
    }

    return (ret);
}
