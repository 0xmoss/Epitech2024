/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** exec_p.c
*/

#include "flags.h"
#include "includes.h"

int check_exec_p(int flags)
{
    if ((flags & EXEC_P) != 0) {
        printf("EXEC_P");
        flags -= EXEC_P;
    }
    return (flags);
}
