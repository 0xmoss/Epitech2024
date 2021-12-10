/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** compare_c.c
*/

#include "string.h"

int compare_c(const string_t *this, const char *str)
{
    if (!this || !this->str || !str)
        return(-1);
    return(strcmp(this->str, str));
}