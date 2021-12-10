/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02M-
** File description:
** add.c
*/

#include <stdio.h>

#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    return (normal_add(a, b));
}

void exec_add(addition_t *operation)
{
    if (operation->add_type == NORMAL)
        operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
    if (operation->add_type == ABSOLUTE)
        operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
}