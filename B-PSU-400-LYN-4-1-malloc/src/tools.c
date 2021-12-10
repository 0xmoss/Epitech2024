/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-malloc-
** File description:
** tools.c
*/

#include "tools.h"
#include "node.h"

int power_2(int size)
{
    int i = 1;

    for (; i < size; i *= 2);

    return (i);
}

size_t get_block_size(node *block)
{
    return (sizeof(block));
}

int get_page_size(size_t size)
{
    int page_size = getpagesize();
    size_t new = 2 * page_size;

    for (; new < size; new *= page_size);

    return (new);
}

size_t check_size(size_t size)
{
    if (size > 0)
        return (1);
    return (0);
}