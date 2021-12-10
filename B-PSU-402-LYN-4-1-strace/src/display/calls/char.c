/*
** EPITECH PROJECT, 2020
** strace
** File description:
** print_types2.c
*/

#include "strace.h"

void sys_char(char c)
{
    if (c > 31 && c < 127)
        printf("%c", c);
    else if (c != '\n' && c != '\0')
        printf("\\%o", c);
}