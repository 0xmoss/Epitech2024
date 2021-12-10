/*
** EPITECH PROJECT, 2020
** teams
** File description:
** cli_logged.c
*/

#include "tools.h"
#include "cli.h"
#include "phaseout.h"

request_data *cli_login(self_t *self,request_data *data)
{
    if (phase_llength(self->all, NULL) == 2) {
        return (update_data(
            self->all[0],
            self->all[1],
            NULL,
            NULL,
            NULL,
            NULL,
            NULL
        ));
    }

    return (data);
}
