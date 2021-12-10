/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-
** File description:
** dump.c
*/

#include <stdio.h>
#include <stddef.h>

#include "double_list.h"

void double_list_dump(double_list_t list)
{
    for (; list != NULL; list = list->next) {
        printf("%f\n", list->value);
    }
}