/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** truncated.h
*/

#include "phaseout.h"

#include "includes.h"

#ifndef TRUNCATED_H
    #define TRUNCATED_H

    size_t x64_check_truncated(Elf64_Shdr *, size_t);
    size_t x64_is_trucated(Elf64_Ehdr *, Elf64_Shdr *, size_t, char *path);
    size_t x64_check_elf(Elf64_Ehdr *);

    size_t x32_check_truncated(Elf32_Shdr *, size_t);
    size_t x32_is_trucated(Elf32_Ehdr *, Elf32_Shdr *, size_t, char *path);
    size_t x32_check_elf(Elf32_Ehdr *);

#endif /* TRUNCATED_H */

