/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** login
*/

#include <string.h>
#include <stdio.h>
#include "logging_server.h"
#include "prototypes.h"

static response_data create_user(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    struct user_entry *user = malloc(sizeof(struct user_entry));
    response_data resp;
    char user_uuid[UUID_STR_LEN] = {0};

    strcpy(user->data.name, data->name);
    uuid_generate(user->data.uuid);
    uuid_unparse(user->data.uuid, user_uuid);
    SLIST_INIT(&user->data.subscribed_head);
    SLIST_INSERT_HEAD(&manager->user_head, user, entries);
    client->data.user = user;
    client->data.user->data.connected = true;
    server_event_user_created(user_uuid, data->name);
    server_event_user_logged_in(user_uuid);
    resp = create_response(OK,
    "You are now authenticated as NAME(%s) UUID(%s).", data->name, user_uuid);
    return resp;
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data login_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    struct client_entry *auth_entry = find_client_by_name(manager, data->name);
    struct user_entry *user = find_user_by_name(manager, data->name);
    char user_uuid[UUID_STR_LEN] = {0};

    if (user == NULL) {
        return create_user(manager, client, data);
    } else {
        if (auth_entry == NULL) {
            client->data.user = user;
            client->data.user->data.connected = true;
            uuid_unparse(client->data.user->data.uuid, user_uuid);
            server_event_user_logged_in(user_uuid);
            return create_response(OK,
            "You are now authenticated as NAME(%s) UUID(%s).",
            data->name, user_uuid);
        } else {
            return create_response(KO,
            "Someone is already authenticated as NAME(%s).", data->name);
        }
    }
}
#pragma GCC diagnostic error "-Wunused-parameter"