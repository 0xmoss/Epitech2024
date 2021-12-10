/*
** EPITECH PROJECT, 2020
** nm
** File description:
** nm64_utils.c
*/

#include "nm.h"

int selection(Elf64_Shdr *shdr, int i)
{
    return (
        shdr[i].sh_type != SHT_NOBITS &&
        shdr[i].sh_name &&
        shdr[i].sh_size > 0 &&
        shdr->sh_flags != SHF_INFO_LINK &&
        (
            shdr[i].sh_addr ||
            (
                !shdr[i].sh_addr &&
                shdr[i].sh_type != SHT_STRTAB &&
                shdr[i].sh_type != SHT_RELA &&
                shdr[i].sh_type != SHT_REL &&
                shdr[i].sh_type != SHT_SYMTAB
            )
        )
    );
}
