/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** has_syms.c
*/

#include "flags.h"
#include "includes.h"

int check_has_syms(int flags)
{
    if ((flags & HAS_SYMS) != 0) {
        printf("HAS_SYMS");
        flags -= HAS_SYMS;
    }
    return (flags);
}
