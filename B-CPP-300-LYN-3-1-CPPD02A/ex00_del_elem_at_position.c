/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-
** File description:
** del_elem_at_position.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "double_list.h"

bool double_list_del_elem_at_position(double_list_t *front_ptr,
unsigned int position)
{
    doublelist_node_t *current;

    if (double_list_get_size(*front_ptr) != 0 &&
    position < double_list_get_size(*front_ptr)) {
        if (position == 0)
            return (double_list_del_elem_at_front(front_ptr));
        current = *front_ptr;
        for (unsigned int i = 0; i < position - 1 && current != NULL &&
        current->next != NULL; i++)
            current = current->next;
        current->next = current->next->next;
        return (true);
    }
    return (false);
}