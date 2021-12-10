/*
** EPITECH PROJECT, 2020
** test
** File description:
** rcx.c
*/

#include "strace.h"

#include "display.h"

unsigned long int rcx(int arg, struct user_regs_struct *registers)
{
    if (arg == 3)
        return (registers->rcx);
    return (84);
}