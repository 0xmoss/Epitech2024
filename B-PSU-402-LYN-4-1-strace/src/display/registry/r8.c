/*
** EPITECH PROJECT, 2020
** test
** File description:
** r8.c
*/

#include "strace.h"

#include "display.h"

unsigned long int r8(int arg, struct user_regs_struct *registers)
{
    if (arg == 4)
        return (registers->r8);
    return (84);
}