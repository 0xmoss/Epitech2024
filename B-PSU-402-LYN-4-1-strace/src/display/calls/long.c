/*
** EPITECH PROJECT, 2020
** strace
** File description:
** long.c
*/

#include "strace.h"

void sys_long(unsigned long int value)
{
    printf("%lu", value);
}