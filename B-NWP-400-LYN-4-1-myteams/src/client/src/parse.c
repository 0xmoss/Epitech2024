/*
** EPITECH PROJECT, 2020
** teams
** File description:
** parse.c
*/

#include "tools.h"
#include "cli.h"
#include "phaseout.h"

response_data recv_data(self_t *self)
{
    response_data data;
    char code_str[6] = {0};
    char size_str[11] = {0};

    recv(self->master, code_str, 5, 0);
    recv(self->master, size_str, 10, 0);
    data.code = atoi(code_str);
    data.size = atoi(size_str);
    data.message = calloc(data.size + 1, sizeof(char));
    recv(self->master, data.message, data.size, 0);

    return (data);
}

int parse(int master, self_t *self)
{
    response_data data = recv_data(self);

    recv_handler(self, data);

    return (0);
}

int parse_event(int master, self_t *self)
{
    char uuid0[UUID_STR_LEN] = {0};
    char uuid1[UUID_STR_LEN] = {0};
    char uuid2[UUID_STR_LEN] = {0};
    char body[BODY_STR_LEN] = {0};
    char name[NAME_STR_LEN] = {0};
    char description[DESCRIPTION_STR_LEN] = {0};
    time_t time;
    int connected = 0;

    self->master = master;
    response_data data = recv_data(self);
    if (phase_startswith(data.message, "New message", EMPTY) == True) {
        sscanf(data.message, "New message from UUID(%[^)]) BODY(%[^)])", uuid0, body);
        client_event_private_message_received(uuid0, body);
    } else if (phase_startswith(data.message, "New team", EMPTY) == True) {
        sscanf(data.message, "New team created with UUID(%[^)]) NAME(%[^)]) DESCRIPTION(%[^)])", uuid0, name, description);
        client_event_team_created(uuid0, name, description);
    } else if (phase_startswith(data.message, "New channel", EMPTY) == True) {
        sscanf(data.message, "New channel created with UUID(%[^)]) NAME(%[^)]) DESCRIPTION(%[^)])", uuid0, name, description);
        client_event_channel_created(uuid0, name, description);
    } else if (phase_startswith(data.message, "New thread", EMPTY) == True) {
        sscanf(data.message, "New thread created with UUID(%[^)]) USER_UUID(%[^)]) TIME(%ld) NAME(%[^)]) BODY(%[^)])", uuid0, uuid1, &time, name, body);
        client_event_thread_created(uuid0, uuid1, time, name, body);
    } else if (phase_startswith(data.message, "New reply", EMPTY) == True) {
        sscanf(data.message, "New reply created with TEAM_UUID(%[^)]) THREAD_UUID(%[^)]) USER_UUID(%[^)]) TIME(%ld) BODY(%[^)])", uuid0, uuid1, uuid2, &time, body);
        client_event_thread_reply_received(uuid0, uuid1, uuid2, body);
    }
}