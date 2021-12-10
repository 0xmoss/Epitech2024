/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** has_debug.c
*/

#include "flags.h"
#include "includes.h"

int check_has_debug(int flags)
{
    if ((flags & HAS_DEBUG) != 0) {
        printf("HAS_DEBUG");
        flags -= HAS_DEBUG;
    }
    return (flags);
}
