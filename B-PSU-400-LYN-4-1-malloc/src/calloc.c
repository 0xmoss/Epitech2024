/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-malloc-
** File description:
** calloc.c
*/


#include "node.h"
#include "calloc.h"
#include "malloc.h"

/* Explanations
**
** Create two block:
**  - Start: get the first block free
**  - currrent: get the lastest block free
**
** check_size(size):          check if the size to malloc is allocable
** new_block(size):           create a new block with the size to alloc
** check_free(size, start):   check if block is free
** create_block(size, start): move the sbrk limit to create a new block
**                            into the page
*/

void *calloc(size_t members, size_t size)
{
    char *data = NULL;

    if (check_size(size) == 0) {
        data = malloc(members * size);
        if (data != NULL) {
            for (size_t i = 0; i < size; i++) {
                data[i] = '\0';
            }
        }
    }

    return (data);
}