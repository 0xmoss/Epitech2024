/*
** EPITECH PROJECT, 2020
** teams
** File description:
** cli_infos.c
*/

#include "cli.h"
#include "tools.h"
#include "phaseout.h"

request_data *cli_list(self_t *self, request_data *data)
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

