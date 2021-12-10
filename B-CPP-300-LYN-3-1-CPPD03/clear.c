/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** clear.c
*/

#include "string.h"

void clear(string_t *this)
{
    memset(this->str, 0, 0);
}