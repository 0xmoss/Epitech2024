/*
** EPITECH PROJECT, 2020
** teams
** File description:
** cli_use.c
*/

#include "cli.h"
#include "tools.h"
#include "phaseout.h"

request_data *cli_use(self_t *self, request_data *data)
{
    self->use = phase_llength(self->all, NULL) - 1;

    return (update_data(
        self->all[0],
        NULL,
        NULL,
        self->use >= 1 ? self->all[1] : NULL,
        self->use >= 2 ? self->all[2] : NULL,
        self->use >= 3 ? self->all[3] : NULL,
        NULL
    ));

    return (data);
}
