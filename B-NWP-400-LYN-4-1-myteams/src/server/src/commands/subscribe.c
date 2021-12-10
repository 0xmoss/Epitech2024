/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** subscribe
*/

#include <string.h>
#include "struct.h"
#include "prototypes.h"
#include "logging_server.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data subscribe_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    uuid_t uuid;
    char user_uuid_str[UUID_STR_LEN];
    struct team_entry *team;
    struct team_ptr_entry *team_ptr = NULL;
    struct user_ptr_entry *user_ptr = NULL;

    uuid_parse(data->uuid0, uuid);
    if ((team = find_team_by_uuid(manager, uuid)) == NULL) {
        return create_response(KO, "Team with UUID(%s) does not exist.",
        data->uuid0);
    }
    team_ptr = malloc(sizeof(struct team_ptr_entry));
    team_ptr->data.team = team;
    user_ptr = malloc(sizeof(struct user_ptr_entry));
    user_ptr->data.user = client->data.user;
    SLIST_INSERT_HEAD(&client->data.user->data.subscribed_head, team_ptr,
    entries);
    SLIST_INSERT_HEAD(&team->data.subscribed_head, user_ptr, entries);
    uuid_unparse(client->data.user->data.uuid, user_uuid_str);
    server_event_user_subscribed(data->uuid0, user_uuid_str);
    return create_response(OK, "You are now subscribed to this team.");
}
#pragma GCC diagnostic error "-Wunused-parameter"