/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** insert_c.c
*/

#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *tmp;
    unsigned int i = 0;
    int ct;
    int len;

    if (!this || !this->str || !str)
        return;
    len = strlen(this->str) + strlen(str) + 1;
    tmp = malloc(sizeof(char) * len);
    if (tmp == NULL)
        return;
    for (; i < pos && this->str[i] != '\0'; i++)
        tmp[i] = this->str[i];
    ct = i;
    for (int j = 0; str[j] != 0; j++)
        tmp[i++] = '\0';
    if (this->str[ct] == '\0') {
        this->assign_c(this, tmp);
        return;
    } else
        while (this->str[ct] != '\0')
            tmp[i++] = this->str[ct++];
    tmp[i] = '\0';
    this->assign_c(this, tmp);
}
