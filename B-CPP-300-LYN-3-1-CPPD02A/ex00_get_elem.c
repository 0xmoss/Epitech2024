/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-
** File description:
** get_elem.c
*/

#include <stdio.h>
#include <stddef.h>

#include "double_list.h"

double double_list_get_elem_at_front(double_list_t list)
{
    if (double_list_get_size(list) == 0)
        return (0);
    return (list->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    if (double_list_get_size(list) == 0)
        return (0);
    for (; list != NULL && list->next != NULL; )
        list = list->next;
    return (list->value);
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int position)
{
    unsigned int size = double_list_get_size(list);
    unsigned int size_list = double_list_get_size(list);

    if (size != 0 ||position <= size_list) {
        for (unsigned int i = 0; i < position &&
        list->next != NULL; list = list->next, i++);
        return (list->value);
    }
    return (0);
}