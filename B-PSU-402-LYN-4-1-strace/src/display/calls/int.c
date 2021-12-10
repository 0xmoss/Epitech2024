/*
** EPITECH PROJECT, 2020
** strace
** File description:
** int.c
*/

#include "strace.h"

void sys_int(unsigned long int value)
{
    printf("%lu", value);
}