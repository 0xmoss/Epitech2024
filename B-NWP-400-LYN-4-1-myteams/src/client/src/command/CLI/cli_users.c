/*
** EPITECH PROJECT, 2020
** teams
** File description:
** cli_users.c
*/

#include "tools.h"
#include "cli.h"
#include "phaseout.h"

request_data *cli_users(self_t *self, request_data *data)
{
    if (phase_llength(self->all, NULL) == 1) {
        return (update_data(
            self->all[0],
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL
        ));
    }

    return (data);
}
