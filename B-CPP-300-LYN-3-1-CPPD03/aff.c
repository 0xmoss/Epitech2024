/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** aff.c
*/

#include "string.h"

void aff(const string_t *this)
{
    for (int i = 0; this->str[i]; i++)
        printf("%c", this->str[i]);
}