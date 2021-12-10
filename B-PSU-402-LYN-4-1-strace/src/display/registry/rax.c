/*
** EPITECH PROJECT, 2020
** test
** File description:
** rax.c
*/

#include "strace.h"

#include "display.h"

unsigned long int rax(int arg, struct user_regs_struct *registers)
{
    if (arg == -1)
        return (registers->rax);
    return (84);
}