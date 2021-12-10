/*
** EPITECH PROJECT, 2020
** teams
** File description:
** command_channel_client.c
*/

#include "tools.h"
#include "cli.h"
#include "phaseout.h"

request_data *cli_create_channel(self_t *self, request_data *data)
{
    if (phase_llength(self->all, NULL) == 3) {
        return (update_data(
            self->all[0],
            self->all[1],
            self->all[2],
            NULL,
            NULL,
            NULL,
            NULL
        ));
    }

    return (data);
}
