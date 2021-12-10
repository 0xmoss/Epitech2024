/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-
** File description:
** recv_list.c
*/

#include "cli.h"
#include "tools.h"

void recv_list(self_t *self, response_data data)
{
    char uuid0[UUID_STR_LEN] = {0};
    char uuid1[UUID_STR_LEN] = {0};
    char body[BODY_STR_LEN] = {0};
    char name[NAME_STR_LEN] = {0};
    char description[DESCRIPTION_STR_LEN] = {0};
    time_t time = 0;
    char *message = NULL;

    while ((message = strtok(message == NULL ? data.message : NULL, "\n"))) {
        if (self->use == 0) {
            sscanf(data.message, "UUID(%[^)]) NAME(%[^)]) DESCRIPTION(%[^)])", uuid0, name, description);
            client_print_teams(uuid0, name, description);
        } else if (self->use == 1) {
            sscanf(data.message, "UUID(%[^)]) NAME(%[^)]) DESCRIPTION(%[^)])", uuid0, name, description);
            client_team_print_channels(uuid0, name, description);
        } else if (self->use == 2) {
            sscanf(data.message, "UUID(%[^)]) AUTHOR_UUID(%[^)]) TIME(%ld) NAME(%[^)]) BODY(%[^)])", uuid0, uuid1, &time, name, body);
            client_channel_print_threads(uuid0, uuid1, time, name, body);
        } else if (self->use == 3) {
            sscanf(data.message, "UUID(%[^)]) AUTHOR_UUID(%[^)]) TIME(%ld) BODY(%[^)])", uuid0, uuid1, &time, body);
            client_thread_print_replies(uuid0, uuid1, time, body);
        } else {
            printf("%s\n", data.message);
        }
    }
}
