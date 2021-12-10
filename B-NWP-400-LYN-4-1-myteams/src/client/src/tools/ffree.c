/*
** EPITECH PROJECT, 2020
** teams
** File description:
** ffree.c
*/

#include "client.h"

void ffree(char **array, int len)
{
    for (int i = 0; i < len; i++)
        free(array[i]);
    free(array);
}
