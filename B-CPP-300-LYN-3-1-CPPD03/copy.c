/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** copy.c
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t index = 0;
    size_t len = 0;

    if (!this || !this->str || !s)
       return (0);
    len = strlen(this->str);
    for (unsigned int i = 0; i < len; i++)
    {
        if (i == pos)
        {
            for (;(i < len) && (index < n) && s; i++)
                s[index++] = this->str[i];
            s[index] = '\0';
        }
        i++;
    }
   return (index);
}
