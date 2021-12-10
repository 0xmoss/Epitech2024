/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-
** File description:
** double_list.c
*/

#include <stdio.h>
#include <stddef.h>

#include "double_list.h"

unsigned int double_list_get_size(double_list_t list)
{
    unsigned int i = 0;

    for (; list != NULL; i++)
        list = list->next;
    return (i);
}