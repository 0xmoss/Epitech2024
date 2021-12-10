/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "tools.h"
#include "cli.h"
#include "phaseout.h"

request_data *cli_team_create(self_t *self, request_data *data)
{
    if (phase_llength(self->all, NULL) == 4) {
        return (update_data(
            self->all[0],
            self->all[2],
            self->all[3],
            self->all[1],
            NULL,
            NULL,
            NULL
        ));
    }

    return (data);
}
