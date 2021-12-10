/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** trucated.c
*/

#include "phaseout.h"

#include "includes.h"
#include "version.h"
#include "truncated.h"

size_t x64_check_truncated(Elf64_Shdr *shdr, size_t i)
{
    if (shdr[i].sh_type != SHT_NOBITS &&
        shdr[i].sh_name &&
        shdr[i].sh_size > 0 &&
        shdr->sh_flags != SHF_INFO_LINK &&
        ((!shdr[i].sh_addr &&
            shdr[i].sh_type != SHT_STRTAB &&
            shdr[i].sh_type != SHT_RELA &&
            shdr[i].sh_type != SHT_REL &&
            shdr[i].sh_type != SHT_SYMTAB) || shdr[i].sh_addr
        )
    )
        return (True);
    return (False);
}

size_t x64_check_elf(Elf64_Ehdr *ehdr)
{
    if (ehdr->e_ident[EI_MAG0] == 0x7F &&
        ehdr->e_ident[EI_MAG1] == 'E' &&
        ehdr->e_ident[EI_MAG2] == 'L' &&
        ehdr->e_ident[EI_MAG3] == 'F' &&
        version(ehdr->e_ident) == 64) {
            return (True);
    }
    return (False);
}

size_t x64_is_trucated(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, size_t size,
char *path)
{
    size_t size_off = ehdr->e_shnum * ehdr->e_shentsize + ehdr->e_shoff;

    if (size_off > size) {
        printf("%s: file truncated\n", path);
        return (False);
    }
    for (size_t i = 0; i < ehdr->e_shnum; i++) {
        if (x64_check_truncated(shdr, i) == True) {
            size_off = shdr[i].sh_size + shdr[i].sh_offset;
            if (size_off > size || x64_check_elf(ehdr) == False) {
                printf("%s: file format not recognized\n", path);
                return (Error);
            }
        }
    }
    return (True);
}
