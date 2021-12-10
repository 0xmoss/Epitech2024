/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-malloc-
** File description:
** node.h
*/

#include "node.h"
#include "tools.h"


node *get_free(size_t size, node *block)
{
    if (block != NULL) {
        for (; block->next != NULL; block = block->next) {
            if (block->free == True && size <= block->size)
                return (block);
        }
    }

    return (NULL);
}

void *create_block(size_t size, node *block)
{
    void *address = sbrk(get_page_size(size));

    if (address == (void *)-1)
        return (NULL);
    for (; block->next != NULL; block = block->next);
    block->next = address;
    block->next->size = size;
    block->next->free = False;
    block->next->previous = block;
    block->next->next = NULL;
    block->next->address = sizeof(node) + address;
    return (block->next);
}

void *new_block(size_t size)
{
    node *new = NULL;
    void *address = NULL;

    address = sbrk(get_page_size(size));
    if (address != (void *)-1) {
        new = address;
        new->size = size;
        new->free = False;
        new->previous = NULL;
        new->next = NULL;
        new->address = sizeof(node) + address;

        return (new);
    }

    return (NULL);
}