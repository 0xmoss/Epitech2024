/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** compare_s.c
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    return(compare_c(this, str->str));
}