/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-
** File description:
** cli_help.c
*/

#include "tools.h"
#include "cli.h"
#include "phaseout.h"

request_data *cli_help(self_t *self, request_data *data)
{
    return (update_data(
        "help\0",
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    ));
}
