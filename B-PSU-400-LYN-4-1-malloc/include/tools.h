/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-malloc-
** File description:
** Tools.h
*/

#include "node.h"

#ifndef _TOOLS_H_
    #define _TOOLS_H_

    // POWER
    int power_2(int);

    // SIZEOF
    size_t get_block_size(node *);

    // PAGES
    int get_page_size(size_t);

    // CHECK
    size_t check_size(size_t);

#endif /* _TOOLS_H_ */