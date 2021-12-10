/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** bfd_no_flags.c
*/

#include "flags.h"
#include "includes.h"

int check_bfd_no_flags(int flags)
{
    if ((flags & BFD_NO_FLAGS) != 0) {
        printf("BFD_NO_FLAGS");
        flags -= BFD_NO_FLAGS;
    }
    return (flags);
}
