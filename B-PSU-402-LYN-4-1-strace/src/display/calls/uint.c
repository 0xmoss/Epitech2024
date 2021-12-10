/*
** EPITECH PROJECT, 2020
** strace
** File description:
** uint.c
*/

#include "strace.h"

void sys_uint(unsigned long int value)
{
    printf("%lu", value);
}