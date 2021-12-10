/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** align.c
*/

#include "phaseout.h"

#include "align.h"

#include "includes.h"

size_t modulo(size_t a, size_t b)
{
    if (a % b == 0)
        return (True);
    return (False);
}

size_t display(size_t a, size_t b, char *str)
{
    if (modulo(a, b) == True) {
        if (str != NULL) {
            if (b == 16)
                printf("%s", str);
            if (b == 4)
                printf("%s", str);
        }
        return (True);
    }
    return (False);
}
