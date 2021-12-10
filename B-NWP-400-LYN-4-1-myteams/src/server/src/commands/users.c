/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** users
*/

#include "struct.h"
#include "prototypes.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data users_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    response_data response = create_temp_response(OK);
    struct user_entry *user;
    char uuid_str[UUID_STR_LEN] = {0};

    SLIST_FOREACH(user, &manager->user_head, entries) {
        uuid_unparse(user->data.uuid, uuid_str);
        append_data(&response, "UUID(%s) NAME(%s) CONNECTED(%d)\n",
        uuid_str, user->data.name, user->data.connected);
    }
    return response;
}
#pragma GCC diagnostic error "-Wunused-parameter"