/*
** EPITECH PROJECT, 2020
** teams
** File description:
** cli_check_team.c
*/

#include "tools.h"
#include "cli.h"
#include "phaseout.h"

request_data *cli_check_team(self_t *self, request_data *data)
{
    if (phase_llength(self->all, NULL) == 4) {
        return (update_data(
            self->all[0],
            self->all[1],
            self->all[2],
            self->all[3],
            NULL,
            NULL,
            NULL
        ));
    }

    return (data);
}
