/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02M-
** File description:
** div.c
*/

#include <stdio.h>

#include "castmania.h"

int integer_div(int a, int b)
{
    int result = 0;

    if (b != 0) {
        result = a / b;
        return (result);
    }
    return (0);
}

float decimale_div(int a, int b)
{
    float result = 0;

    if (b != 0) {
        result = (float)a / (float)b;
        return (result);
    }
    return (0);
}

void exec_div(division_t *operation)
{
    integer_op_t *int_op;
    decimale_op_t *dec_op;

    if (operation->div_type == INTEGER) {
        int_op = (integer_op_t*)operation->div_op;
        int_op->res = integer_div(int_op->a, int_op->b);
    } else if (operation->div_type == DECIMALE) {
        dec_op = (decimale_op_t*)operation->div_op;
        dec_op->res = integer_div(dec_op->a, dec_op->b);
    }
}