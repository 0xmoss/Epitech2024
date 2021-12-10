/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** find_s.c
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return (find_c(this, str->str, pos));
}