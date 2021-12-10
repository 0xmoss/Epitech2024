/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-malloc-
** File description:
** realloc.c
*/

#include "node.h"
#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    node *block_start = NULL;
    void *new_block = NULL;

    if (ptr != NULL) {
        if (size > 0) {
            block_start = ptr - sizeof(node);
            if (block_start->free != True && block_start->size < size) {
                new_block = malloc(size);
                if (new_block != NULL)
                    memcpy(new_block, block_start + sizeof(node),
                        block_start->size);
                free(ptr);
                return (new_block);
            }
        }
        free(ptr);
        return (NULL);
    }
    return (malloc(size));
}