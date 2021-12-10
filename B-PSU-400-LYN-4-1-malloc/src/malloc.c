/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-malloc-
** File description:
** malloc.c
*/

#include "node.h"
#include "malloc.h"
#include "tools.h"

void *malloc(size_t size)
{
    node *block_start = NULL;
    node *block_current = NULL;

    if (check_size(size) == 1) {
        if (block_start == NULL) {
            block_start = new_block(size);
            if (block_start != NULL)
                return (block_start->address);
        }
        block_current = get_free(size, block_start);
        if (block_current != NULL) {
            block_current->free = False;
            return (block_current->address);
        } else {
            block_current = create_block(size, block_start);
            if (block_current != NULL)
                return (block_current->address);
        }
    }

    return (NULL);
}