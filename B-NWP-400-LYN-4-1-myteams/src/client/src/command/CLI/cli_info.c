/*
** EPITECH PROJET, 2020
** teams
** File description:
** cli_info.c
*/

#include "cli.h"
#include "tools.h"

request_data *cli_info(self_t *self, request_data *data)
{
    return (update_data(
        "info\0",
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    ));
}

