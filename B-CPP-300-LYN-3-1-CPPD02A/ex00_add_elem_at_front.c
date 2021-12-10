/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-
** File description:
** add_elem_at_front.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "double_list.h"

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *new;

    new = malloc(sizeof(*new));
    if (new != NULL) {
        new->value = elem;
        new->next = *front_ptr;
        *front_ptr = new;
        return (true);
    }
    return (false);
}