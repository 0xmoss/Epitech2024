/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** s_destroy.c
*/

#include "string.h"

void string_destroy(string_t *this)
{
    if (this && this->str)
        free(this->str);
}