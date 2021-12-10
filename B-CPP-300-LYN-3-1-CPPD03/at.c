/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** at.c
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (!this && pos > strlen(this->str))
        return (-1);
    return (this->str[pos]);
}