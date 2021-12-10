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

#include "includes.h"

size_t x32_dump_header(Elf32_Ehdr *ehdr, Elf32_Shdr *shdr, char *path,
Elf32_Addr address)
{
    int flags = BFD_NO_FLAGS;

    printf("\n%s:%s file format elf32-i386\n", path, S_TAB_4);
    flags = x32_flags_check(ehdr, shdr, flags);
    printf("architecture: i386:x86-32, flags 0x%08x:\n", flags);
    x32_flags_display(flags);
    printf("\nstart address 0x%018x\n\n", address);
    return (True);
}

size_t x32_dump_selection(Elf32_Shdr shdr, char *buffer)
{
    Elf64_Addr tmp = shdr.sh_addr;
    size_t i = 0;

    for (; i < shdr.sh_size;) {
        if (modulo(i, 16) == True) {
            printf(" %04lx ", tmp);
            tmp += 16;
            x32_characters_hexa(shdr, buffer, i);
        }
        x32_characters_get((unsigned char)(buffer + shdr.sh_offset)[i]);
        i++;
        if (modulo(i, 16) == True)
            printf(S_LINE);
    }
    if (i >= shdr.sh_size && modulo(i, 16) == False)
        x32_characters_space(i, True);
    return (True);
}

size_t x32_dump_dump(Elf32_Ehdr *ehdr, Elf32_Shdr *shdr, char *tab,
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
            x32_dump_selection(shdr[i], buffer);
        }
    }
    return (True);
}
