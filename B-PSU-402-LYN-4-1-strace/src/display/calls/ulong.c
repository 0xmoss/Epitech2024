/*
** EPITECH PROJECT, 2020
** strace
** File description:
** ulong.c
*/

#include "strace.h"

void sys_ulong(unsigned long int value)
{
    printf("%lu", value);
}