/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** dump.c
*/

#include "phaseout.h"

#include "flags.h"
#include "tools.h"
#include "align.h"
#include "selection.h"
#include "dump.h"
#include "address.h"

#include "includes.h"

size_t x64_dump_header(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, char *path,
Elf64_Addr address)
{
    int flags = BFD_NO_FLAGS;

    printf("\n%s:%s file format elf64-x86-64\n", path, S_TAB_4);
    flags = x64_flags_check(ehdr, shdr, flags);
    printf("architecture: i386:x86-64, flags 0x%08x:\n", flags);
    x64_flags_display(flags);
    printf("\nstart address 0x%016lx\n\n", address);
    return (True);
}

size_t x64_dump_selection(Elf64_Shdr shdr, char *buffer)
{
    unsigned int tmp = shdr.sh_addr;
    unsigned int i = 0;

    for (; i < shdr.sh_size;) {
        if (modulo(i, 16) == True) {
            printf(" %04x ", tmp);
            tmp += 16;
            x64_characters_hexa(shdr, buffer, i);
        }
        x64_characters_get((buffer + shdr.sh_offset)[i]);
        i++;
        if (modulo(i, 16) == True)
            printf(S_LINE);
    }
    if (i >= shdr.sh_size && modulo(i, 16) != True)
        x64_characters_space(i, True);
    return (True);
}

size_t x64_dump_dump(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, char *tab,
char *buffer)
{
    for (size_t i = 0; i < ehdr->e_shnum; i++) {
        if ((tab + shdr[i].sh_name)[0] != '\0' &&
            strstr(tab + shdr[i].sh_name, ".rela") == NULL &&
            strcmp(tab + shdr[i].sh_name, ".bss") != 0 &&
            strcmp(tab + shdr[i].sh_name, ".shstrtab") != 0 &&
            strcmp(tab + shdr[i].sh_name, ".symtab") != 0    &&
            strcmp(tab + shdr[i].sh_name, ".strtab")  != 0) {
            printf("Contents of section %s:\n", tab + shdr[i].sh_name);
            x64_dump_selection(shdr[i], buffer);
        }
    }
    return (True);
}
