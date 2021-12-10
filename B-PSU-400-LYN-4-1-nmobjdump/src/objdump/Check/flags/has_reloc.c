/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** has_reloc.c
*/

#include "flags.h"
#include "includes.h"

int check_has_reloc(int flags)
{
    if ((flags & HAS_RELOC) != 0) {
        printf("HAS_RELOC");
        flags -= HAS_RELOC;
    }
    return (flags);
}
