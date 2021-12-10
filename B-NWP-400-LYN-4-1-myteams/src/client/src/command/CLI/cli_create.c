/*
** EPITECH PROJECT, 2020
** teams
** File description:
** cli_create.c
*/

#include "cli.h"
#include "tools.h"
#include "phaseout.h"

static request_data *validation(self_t *self, request_data *data, size_t size)
{
    if (size == 3) {
        return (update_data(
            self->all[0],
            self->all[1],
            self->use != 2 ? self->all[2] : NULL,
            NULL,
            NULL,
            NULL,
            self->use == 2 ? self->all[2] : NULL
        ));
    }

    return (data);
}

request_data *cli_create(self_t *self, request_data *data)
{
    int size = phase_llength(self->all, NULL);

    if (size == 2) {
        return (update_data(
            self->all[0],
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            self->all[1]
        ));
    }

    return (validation(self, data, size));
}
