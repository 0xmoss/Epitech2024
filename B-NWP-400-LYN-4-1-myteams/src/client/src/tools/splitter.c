/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-
** File description:
** splitter.c
*/

#include "client.h"
#include "tools.h"
#include "phaseout.h"

char **splitter(char *data, char delim)
{
    int count = phase_count(data, delim, EMPTY);
    char **command = malloc(sizeof(char * ) * count);
    int index = 0;
    char *ptr = NULL;

    while ((ptr = strtok(ptr ? NULL : ptr, " "))) {
        command[index++] = ptr;
    }

    return (command);
}