/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** version.c
*/

#include "phaseout.h"

#include "includes.h"

#include "version.h"

size_t version(unsigned const char *e_ident)
{
    if (e_ident[EI_CLASS] == ELFCLASS64)
        return (64);
    if (e_ident[EI_CLASS] == ELFCLASS32)
        return (32);
    return (False);
}
