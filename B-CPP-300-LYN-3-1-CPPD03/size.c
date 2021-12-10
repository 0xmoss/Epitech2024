/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** size.c
*/

#include "string.h"

int size(const string_t *this)
{
    int size;
    
    if (!this || !this->str)
        return(-1);
    size = strlen(this->str);
    return(size);
}