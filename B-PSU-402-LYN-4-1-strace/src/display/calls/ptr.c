/*
** EPITECH PROJECT, 2020
** strace
** File description:
** ptr.c
*/

#include "strace.h"

void sys_ptr(unsigned long int value)
{
    if (value == 0)
        printf("NULL");
    else
        printf("%p", (void*)value);
}