/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-
** File description:
** recv_info.c
*/

#include "cli.h"
#include "tools.h"
#include "phaseout.h"

void recv_info(self_t *self, response_data data)
{
    char uuid0[UUID_STR_LEN] = {0};
    char uuid1[UUID_STR_LEN] = {0};
    char name[NAME_STR_LEN] = {0};
    char description[DESCRIPTION_STR_LEN] = {0};
    char body[BODY_STR_LEN] = {0};
    time_t time;
    int connected = 0;

    if (phase_startswith(data.message, "Your info", '\0')) {
        sscanf(data.message, "Your info are UUID(%[^)]) NAME(%[^)]) CONNECTED(%d)", uuid0, name, &connected);
        client_print_user(uuid0, name, connected);
    } else if (phase_startswith(data.message, "Selected team", '\0')) {
        sscanf(data.message, "Selected team info are UUID(%[^)]) NAME(%[^)]) DESCRIPTION(%[^)])", uuid0, name, description);
        client_print_team(uuid0, name, description);
    } else if (phase_startswith(data.message, "Selected channel", '\0')) {
        sscanf(data.message, "Selected channel info are UUID(%[^)]) NAME(%[^)]) DESCRIPTION(%[^)])", uuid0, name, description);
        client_print_channel(uuid0, name, description);
    } else if (phase_startswith(data.message, "Selected thread", '\0')) {
        sscanf(data.message, "Selected thread info are UUID(%[^)]) AUTHOR_UUID(%[^)]) TIME(%ld) NAME(%[^)]) BODY(%[^)])", uuid0, uuid1, &time, name, body);
        client_print_thread(uuid0, uuid1, time, name, body);
    }
}
