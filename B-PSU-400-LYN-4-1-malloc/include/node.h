/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-malloc-
** File description:
** node.h
*/

#ifndef _NODE_H_
    #define _NODE_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>

    #include "bool.h"

    typedef struct node_s node;

    struct node_s
    {
        size_t size;
        node *previous;
        node *next;
        int free;
        void *address;
    };

    node *get_free(size_t, node *);
    void *create_block(size_t, node *);
    void *new_block(size_t);

#endif /* _NODE_H_ */