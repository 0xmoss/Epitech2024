/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-
** File description:
** recv_help.c
*/

#include "client.h"
#include "tools.h"
#include "logging_client.h"

void recv_help(self_t *self, response_data data)
{
    printf("%s\n", data.message);

    return;
}
