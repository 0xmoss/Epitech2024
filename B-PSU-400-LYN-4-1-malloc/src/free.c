/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-malloc-
** File description:
** free.c
*/

#include "node.h"
#include "tools.h"

int free_next(node *block)
{
    block->size += sizeof(node) + block->next->size;
    block->next->next->previous = block;
    block->next = block->next->next;

    return (True);
}

int free_previous(node *block)
{
    block->size += sizeof(node) + block->previous->size;
    block->previous->previous->next = block;
    block->previous = block->previous->previous;

    return (True);
}

void free(void *ptr)
{
    node *block = NULL;

    if (ptr != NULL) {
        for (; block != NULL; block = block->next) {
            if (block->address == ptr) {
                block->free = True;
                if (block->previous->free == True)
                    free_previous(block);
                if (block->next->free == True)
                    free_next(block);
            }
        }
    }
}