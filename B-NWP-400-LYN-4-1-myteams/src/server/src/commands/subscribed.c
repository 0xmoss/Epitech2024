/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** subscribed
*/

#include "struct.h"
#include "prototypes.h"

static response_data subscribed_users_command(
    client_manager *manager, char uuid_str[UUID_STR_LEN])
{
    response_data response;
    uuid_t uuid;
    struct team_entry *team;
    struct user_ptr_entry *user_ptr;

    uuid_parse(uuid_str, uuid);
    if ((team = find_team_by_uuid(manager, uuid)) != NULL) {
        response = create_temp_response(OK);
        append_data(&response,
        "The users subscribed to this team are:\n");
        SLIST_FOREACH(user_ptr, &team->data.subscribed_head, entries) {
            uuid_unparse(user_ptr->data.user->data.uuid, uuid_str);
            append_data(&response, "UUID(%s) NAME(%s) CONNECTED(%d)\n",
            uuid_str, user_ptr->data.user->data.name,
            user_ptr->data.user->data.connected);
        }
        return response;
    } else {
        return create_response(KO, "This team doesn't exist.");
    }
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data subscribed_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    response_data response;
    struct team_ptr_entry *team_ptr;
    char uuid_str[UUID_STR_LEN] = {0};

    if (data->info & UUID0) {
        return subscribed_users_command(manager, data->uuid0);
    } else {
        response = create_temp_response(OK);
        append_data(&response,
        "You are currently subscribed in:\n");
        SLIST_FOREACH(team_ptr, &client->data.user->data.subscribed_head,
        entries) {
            uuid_unparse(team_ptr->data.team->data.uuid, uuid_str);
            append_data(&response, "UUID(%s) NAME(%s) DESCRIPTION(%d)\n",
            uuid_str, team_ptr->data.team->data.name,
            team_ptr->data.team->data.description);
        }
    }
    return response;
}
#pragma GCC diagnostic error "-Wunused-parameter"