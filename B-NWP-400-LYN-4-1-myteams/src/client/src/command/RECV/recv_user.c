/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-
** File description:
** recv_user.c
*/

#include "tools.h"
#include "cli.h"

void recv_user(self_t *self, response_data data)
{
    char name[NAME_STR_LEN] = {0};
    char uuid[UUID_STR_LEN] = {0};
    int status = 0;

    if (data.code == KO) {
        client_error_unknown_user(self->all[1]);
    } else if (data.code == OK) {
        sscanf(data.message, "This user is UUID(%[^)]) NAME(%[^)]) CONNECTED(%d)", name, uuid, &status);
        client_print_user(uuid, name, status);
    }
}
