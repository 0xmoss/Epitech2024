/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** find_c.c
*/

#include "string.h"

int find_c(const string_t *this, const char *str, size_t pos)
{
    int str_len;
    unsigned int this_len;
    int j = 0;
    int n = 0;

    if (!this || !this->str || !str)
        return(-1);
    str_len = strlen(str);
    this_len = strlen(this->str);
    for (unsigned int i = 0;
        i < this_len && this->str[i] != '\0'; i++) {
        if (i == pos)
            for (; i < this_len && this->str[i] != '\0'; i++) {
                j = 0;
                if (this->str[i] == str[j]) {
                    n = i;
                    while (j < str_len && str[j] != '\0')
                        if (str[j] == this->str[i++])
                            j++;
                        else
                            break;
                    if (str[j] == '\0')
                        return(n);
                }
            }
    }
    return(n);
}