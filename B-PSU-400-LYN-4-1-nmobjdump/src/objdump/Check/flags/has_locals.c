/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** has_locals.c
*/

#include "flags.h"
#include "includes.h"

int check_has_locals(int flags)
{
    if ((flags & HAS_LOCALS) != 0) {
        printf("HAS_LOCALS");
        flags -= HAS_LOCALS;
    }
    return (flags);
}
