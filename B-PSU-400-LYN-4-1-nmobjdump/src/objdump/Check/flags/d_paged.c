/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** d_paged.c
*/

#include "flags.h"
#include "includes.h"

int check_d_paged(int flags)
{
    if ((flags & D_PAGED) != 0) {
        printf("D_PAGED");
        flags -= D_PAGED;
    }
    return (flags);
}
