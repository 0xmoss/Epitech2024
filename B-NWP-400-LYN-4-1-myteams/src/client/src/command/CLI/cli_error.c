/*
** EPITECH PROJECT, 2020
** teams
** File description:
** cli_error.c
*/

#include "tools.h"
#include "cli.h"
#include "phaseout.h"

request_data *cli_error(self_t *self, request_data *data)
{
    if (phase_equals(self->all[1], "user\0", EMPTY) == True)
        client_error_unknown_user(self->all[1]);
    if (phase_equals(self->all[1], "unauthoriz\0", EMPTY) == True)
        client_error_unauthorized();
    if (phase_equals(self->all[1], "exist\0", EMPTY) == True)
        client_error_already_exist();
    if (phase_equals(self->all[1], "team\0", EMPTY) == True)
        client_error_unknown_team(self->all[1]);
}
