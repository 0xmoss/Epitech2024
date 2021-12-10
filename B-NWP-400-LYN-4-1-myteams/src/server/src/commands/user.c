/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** user
*/

#include "struct.h"
#include "prototypes.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data user_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    uuid_t uuid;
    struct user_entry *user;

    uuid_parse(data->uuid0, uuid);
    user = find_user_by_uuid(manager, uuid);
    if (user != NULL) {
        return create_response(OK,
        "This user is UUID(%s) NAME(%s) CONNECTED(%d)",
        data->uuid0, user->data.name, user->data.connected);
    } else {
        return create_response(KO, "This user does not exist.");
    }
}
#pragma GCC diagnostic error "-Wunused-parameter"