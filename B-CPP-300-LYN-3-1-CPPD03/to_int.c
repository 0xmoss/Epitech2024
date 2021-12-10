/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** to_int.c
*/

#include "string.h"

int to_int(const string_t *this)
{
    if (!this || !this->str)
        return(0);
    else
        return(atoi(this->str));
}