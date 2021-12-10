/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** has_dynamic.c
*/

#include "flags.h"
#include "includes.h"

int check_has_dynamic(int flags)
{
    if ((flags & HAS_DYNAMIC) != 0) {
        printf("HAS_DYNAMIC");
        flags -= HAS_DYNAMIC;
    }
    return (flags);
}
