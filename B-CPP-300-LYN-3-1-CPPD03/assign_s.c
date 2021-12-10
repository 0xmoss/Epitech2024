/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** assign_s.c
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (!this || !str || !this->str)
        return;
    string_destroy(this);
    this->str = strdup(str->str);
}