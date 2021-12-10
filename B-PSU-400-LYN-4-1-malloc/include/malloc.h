/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-malloc-
** File description:
** malloc.h
*/

#ifndef _MALLOC_H_
    #define _MALLOC_H_

    #include "node.h"

    // TOOLS
    size_t check_size(size_t);    
    int get_page_size(size_t);

    // MALLOC
    void *malloc(size_t);

#endif /* _MALLOC_H_ */