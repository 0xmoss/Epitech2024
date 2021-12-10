/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** append_c.c
*/

#include "string.h"

void append_c(string_t *this, const char *ap)
{
    char *tmp;
    char *strr;

    if (!ap || !this || !this->str)
        return;
    tmp = malloc(sizeof(char) * (strlen(this->str) + strlen(ap) + 1));
    strr = strdup(this->str);
    tmp[0] = '\0';
    if (!tmp || !strr)
        return;
    if (this->str != NULL) {
        tmp = strcat(tmp, strr);
        tmp = strcat(tmp, ap);
    }
    this->str = tmp;
}