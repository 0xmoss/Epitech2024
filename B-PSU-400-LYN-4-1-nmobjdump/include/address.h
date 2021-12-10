/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** address.h
*/

#include "phaseout.h"

#include "includes.h"

#ifndef ADDRESS_H
    #define ADDRESS_H

    Elf64_Addr x64_address(Elf64_Shdr *, Elf64_Ehdr *, char *);
    Elf32_Addr x32_address(Elf32_Shdr *, Elf32_Ehdr *, char *);

#endif /* ADDRESS_H */
