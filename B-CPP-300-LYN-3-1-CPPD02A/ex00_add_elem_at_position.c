/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-
** File description:
** add_elem_at_position.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "double_list.h"

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
unsigned int position)
{
    doublelist_node_t *new;
    doublelist_node_t *current;

    new = malloc(sizeof(*new));
    if (new != NULL && position <= double_list_get_size(*front_ptr)) {
        new->value = elem;
        current = *front_ptr;
        for (unsigned int i = 0; i < position - 1 && current != NULL &&
        current->next != NULL; i++)
            current = current->next;
        new->next = position == 0 ? *front_ptr : current->next;
        if (position == 0)
            *front_ptr = new;
        else
            current->next = new;
        return (true);
    }
    return (false);
}