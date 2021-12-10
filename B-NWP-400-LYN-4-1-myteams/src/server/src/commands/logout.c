/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** logout
*/

#include <string.h>
#include "struct.h"
#include "prototypes.h"
#include "logging_server.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data logout_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    response_data resp;
    char user_uuid[UUID_STR_LEN];

    uuid_unparse(client->data.user->data.uuid, user_uuid);
    resp = create_response(OK, "You are now disconnected as UUID(%s) NAME(%s).", user_uuid, client->data.user->data.name);
    client->data.user->data.connected = false;
    client->data.user = NULL;
    server_event_user_logged_out(user_uuid);
    return resp;
}
#pragma GCC diagnostic error "-Wunused-parameter"