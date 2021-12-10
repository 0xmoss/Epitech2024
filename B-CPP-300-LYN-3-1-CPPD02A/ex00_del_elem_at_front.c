/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-
** File description:
** del_elem_at_front.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "double_list.h"

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    doublelist_node_t	*new_first;

    if (double_list_get_size(*front_ptr) == 0)
        return (false);
    new_first = *front_ptr;
    new_first = new_first->next;
    *front_ptr = new_first;
    return (true);
}