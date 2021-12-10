/*
** EPITECH PROJECT, 2020
** test
** File description:
** rsi.c
*/

#include "strace.h"

#include "display.h"

unsigned long int rsi(int arg, struct user_regs_struct *registers)
{
    if (arg == 1)
        return (registers->rsi);
    return (84);
}