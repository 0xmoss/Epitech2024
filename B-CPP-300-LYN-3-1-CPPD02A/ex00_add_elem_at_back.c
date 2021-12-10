/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-
** File description:
** add_elem_at_back.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "double_list.h"

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *new;
    doublelist_node_t *current;

    new = malloc(sizeof(*new));
    if (new != NULL) {
        new->value = elem;
        new->next = NULL;
        if (!*front_ptr) {
            *front_ptr = new;
        } else {
            current = *front_ptr;
            for (; current != NULL && current->next != NULL; ) {
                current = current->next;
            }
            current->next = new;
        }
        return (true);
    }
    return (false);
}