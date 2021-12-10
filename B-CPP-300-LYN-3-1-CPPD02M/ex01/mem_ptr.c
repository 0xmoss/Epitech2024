/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02M-
** File description:
** mem_ptr.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mem_ptr.h"

void add_str(char *str1, char *str2, char **res)
{
    int size = strlen(str1) + strlen(str2);
    char *tmp = malloc(sizeof(char) * size + 1);

    tmp = strcat(tmp, str1);
    tmp = strcat(tmp, str2);
    *res = tmp;
}

void add_str_struct(str_op_t *str_op)
{
    int size = strlen(str_op->str1) + strlen(str_op->str2);
    char *tmp = malloc(sizeof(char) * size + 1);

    tmp = strcat(tmp, str_op->str1);
    tmp = strcat(tmp, str_op->str2);
    str_op->res = tmp;
}