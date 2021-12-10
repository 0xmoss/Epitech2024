/*
** EPITECH PROJECT, 2020
** teams
** File description:
** cli_send.c
*/

#include "tools.h"
#include "cli.h"
#include "phaseout.h"

request_data *cli_send(self_t *self, request_data *data)
{
    if (phase_llength(self->all, NULL) == 3) {
        return (update_data(
            self->all[0],
            NULL,
            NULL,
            self->all[1],
            NULL,
            NULL,
            self->all[2]
        ));
    }

    return (data);
}
