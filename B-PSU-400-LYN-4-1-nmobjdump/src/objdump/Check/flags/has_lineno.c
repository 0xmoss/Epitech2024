/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** has_lineno.c
*/

#include "flags.h"
#include "includes.h"

int check_has_lineno(int flags)
{
    if ((flags & HAS_LINENO) != 0) {
        printf("HAS_LINENO");
        flags -= HAS_LINENO;
    }
    return (flags);
}
