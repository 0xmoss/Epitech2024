/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-
** File description:
** del_elem_at_back.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "double_list.h"

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    doublelist_node_t	*current;

    if (double_list_get_size(*front_ptr) == 0)
        return (false);
    current = *front_ptr;
    for (; current != NULL && current->next != NULL &&
    current->next->next != NULL; )
        current = current->next;
    if (current->next == NULL)
        *front_ptr = NULL;
    else
        current->next = NULL;
    return (true);
}