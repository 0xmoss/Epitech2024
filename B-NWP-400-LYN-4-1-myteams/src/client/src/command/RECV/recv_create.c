/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-
** File description:
** recv_use.c
*/

#include "client.h"
#include "tools.h"
#include "logging_client.h"

void recv_create(self_t *self, response_data data)
{
    char name[NAME_STR_LEN] = {0};
    char uuid[UUID_STR_LEN] = {0};
    char uuid2[UUID_STR_LEN] = {0};
    char uuid3[UUID_STR_LEN] = {0};
    char description[DESCRIPTION_STR_LEN] = {0};
    char body[BODY_STR_LEN] = {0};
    time_t time;

    if (phase_startswith(data.message, "New team", '\0')) {
        sscanf(data.message, "New team created with UUID(%[^)]) NAME(%[^)]) DESCRIPTION(%[^)])", uuid, name, description);
        client_print_team_created(uuid, name, description);
    } else if (phase_startswith(data.message, "New channel", '\0')) {
        sscanf(data.message, "New channel created with UUID(%[^)]) NAME(%[^)]) DESCRIPTION(%[^)])", uuid, name, description);
        client_print_channel_created(uuid, name, description);
    } else if (phase_startswith(data.message, "New thread", '\0')) {
        sscanf(data.message, "New thread created with UUID(%[^)]) USER_UUID(%[^)]) TIME(%ld) NAME(%[^)]) BODY(%[^)])", uuid, uuid2, &time, name, body);
        client_print_thread_created(uuid, uuid2, time, name, body);
    } else if (phase_startswith(data.message, "New reply", '\0')) {
        sscanf(data.message, "New reply created with TEAM_UUID(%[^)]) THREAD_UUID(%[^)]) USER_UUID(%[^)]) TIME(%ld) BODY(%[^)])", uuid, uuid2, uuid3, &time, description);
        client_print_reply_created(uuid2, uuid3, time, body);
    }
}