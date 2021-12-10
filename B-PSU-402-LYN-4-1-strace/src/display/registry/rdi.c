/*
** EPITECH PROJECT, 2020
** test
** File description:
** rdi.c
*/

#include "strace.h"

#include "display.h"

unsigned long int rdi(int arg, struct user_regs_struct *registers)
{
    if (arg == 0)
        return (registers->rdi);
    return (84);
}