/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** adress.c
*/

#include "phaseout.h"

#include "flags.h"
#include "address.h"
#include "includes.h"

Elf64_Addr x64_address(Elf64_Shdr *shdr, Elf64_Ehdr *ehdr, char *tab)
{
    for (size_t i = 0; i < ehdr->e_shnum; i++) {
        if (phase_equals(tab + shdr[i].sh_name, ".text\0", EMPTY) == True)
            return (shdr[i].sh_addr);
    }
    return (0);
}

