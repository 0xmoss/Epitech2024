/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** assign_c_s.c
*/

#include "string.h"

void assign_c(string_t *this, const char *s)
{
    if (!this || !s || !this->str)
        return;
    string_destroy(this);
    this->str = strdup(s);
}