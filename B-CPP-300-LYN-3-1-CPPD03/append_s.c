/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** append_s.c
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    append_c(this, ap->str);
}