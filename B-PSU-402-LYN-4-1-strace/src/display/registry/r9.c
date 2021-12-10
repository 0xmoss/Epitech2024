/*
** EPITECH PROJECT, 2020
** test
** File description:
** r9.c
*/

#include "strace.h"

#include "display.h"

unsigned long int r9(int arg, struct user_regs_struct *registers)
{
    if (arg == 5)
        return (registers->r9);
    return (84);
}