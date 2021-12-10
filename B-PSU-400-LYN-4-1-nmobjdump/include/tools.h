/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** characters.h
*/

#include "phaseout.h"

#include "includes.h"

#ifndef CHARACTERS_H
    #define CHARACTERS_H

    size_t x64_characters_get(unsigned char);
    size_t x64_characters_space(size_t, char);
    size_t x64_characters_hexa(Elf64_Shdr, char *, size_t);

    size_t x32_characters_get(unsigned char);
    size_t x32_characters_space(size_t, char);
    size_t x32_characters_hexa(Elf32_Shdr, char *, size_t);

#endif /* CHARACTERS_H */
