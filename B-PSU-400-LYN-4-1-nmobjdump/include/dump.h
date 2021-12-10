/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** dump.h
*/

#include "phaseout.h"
#include "includes.h"

#ifndef DUMP_H
    #define DUMP_H

    size_t x64_dump_header(Elf64_Ehdr *, Elf64_Shdr *, char *, Elf64_Addr);
    size_t x64_dump_selection(Elf64_Shdr, char *);
    size_t x64_dump_dump(Elf64_Ehdr *, Elf64_Shdr *, char *, char *);

    size_t x32_dump_header(Elf32_Ehdr *, Elf32_Shdr *, char *, Elf32_Addr);
    size_t x32_dump_selection(Elf32_Shdr, char *);
    size_t x32_dump_dump(Elf32_Ehdr *, Elf32_Shdr *, char *, char *);

#endif /* DUMP_H */
