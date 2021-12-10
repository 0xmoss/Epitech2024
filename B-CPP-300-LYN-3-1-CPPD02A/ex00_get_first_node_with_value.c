/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-
** File description:
** get_first_node_with_value.c
*/

#include <stdio.h>
#include <stddef.h>

#include "double_list.h"

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    doublelist_node_t *current;

    current = list;
    for (; current != NULL && current->next != NULL; current = current->next) {
        if (current->value == value)
            return (current);
    }
    return (NULL);
}