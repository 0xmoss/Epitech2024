/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** empty.c
*/

#include "string.h"

int empty(const string_t *this)
{
    if (this && this->str && this->str[0] == '\0')
        return(1);
    return(-1);
}