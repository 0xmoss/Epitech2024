/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** info
*/

#include "struct.h"
#include "prototypes.h"

static response_data info_user(struct client_entry *client)
{
    char uuid_str[UUID_STR_LEN];

    uuid_unparse(client->data.user->data.uuid, uuid_str);
    return create_response(OK, "Your info are UUID(%s) NAME(%s) CONNECTED(%d)",
    uuid_str, client->data.user->data.name, client->data.user->data.connected);
}

static response_data info_team(struct client_entry *client)
{
    char uuid_str[UUID_STR_LEN];

    uuid_unparse(client->data.team->data.uuid, uuid_str);
    return create_response(OK,
    "Selected team info are UUID(%s) NAME(%s) DESCRIPTION(%d)",
    uuid_str, client->data.team->data.name,
    client->data.team->data.description);
}

static response_data info_channel(struct client_entry *client)
{
    char uuid_str[UUID_STR_LEN];

    uuid_unparse(client->data.channel->data.uuid, uuid_str);
    return create_response(OK,
    "Selected channel info are UUID(%s) NAME(%s) DESCRIPTION(%d)",
    uuid_str, client->data.channel->data.name,
    client->data.channel->data.description);
}

static response_data info_thread(struct client_entry *client)
{
    char uuid_str[UUID_STR_LEN];
    char user_uuid_str[UUID_STR_LEN];

    uuid_unparse(client->data.thread->data.uuid, uuid_str);
    uuid_unparse(client->data.thread->data.author_uuid, user_uuid_str);
    return create_response(OK,
    "Selected thread info are UUID(%s) AUTHOR_UUID(%s) TIME(%ld) NAME(%s)"
    "BODY(%s)", uuid_str, user_uuid_str, client->data.thread->data.time,
    client->data.thread->data.name, client->data.thread->data.message);
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data info_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    enum use_state state = get_use_state(client);
    response_data response;

    switch (state) {
        case USE_NONE:
            response = info_user(client);
            break;
        case USE_TEAM:
            response = info_team(client);
            break;
        case USE_CHANNEL:
            response = info_channel(client);
            break;
        case USE_THREAD:
            response = info_thread(client);
            break;
        default:
            response = create_response(KO, "Invalid usage of /use.");
            break;
    }
    return response;
}
#pragma GCC diagnostic error "-Wunused-parameter"