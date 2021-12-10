/*
** EPITECH PROJECT, 2020
** test
** File description:
** rdx.c
*/

#include "strace.h"

#include "display.h"

unsigned long int rdx(int arg, struct user_regs_struct *registers)
{
    if (arg == 2)
        return (registers->rdx);
    return (84);
}