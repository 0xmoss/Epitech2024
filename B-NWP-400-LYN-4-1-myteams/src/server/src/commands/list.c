/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** list
*/

#include "struct.h"
#include "prototypes.h"

static response_data list_team(client_manager *manager)
{
    struct team_entry *team;
    response_data response = create_temp_response(OK);
    char uuid_str[UUID_STR_LEN];

    SLIST_FOREACH(team, &manager->team_head, entries) {
        uuid_unparse(team->data.uuid, uuid_str);
        append_data(&response, "UUID(%s) NAME(%s) DESCRIPTION(%s)\n",
        uuid_str, team->data.name, team->data.description);
    }
    return response;
}

static response_data list_channel(struct client_entry *client)
{
    struct channel_entry *channel;
    response_data response = create_temp_response(OK);
    char uuid_str[UUID_STR_LEN];

    SLIST_FOREACH(channel, &client->data.team->data.channel_head, entries) {
        uuid_unparse(channel->data.uuid, uuid_str);
        append_data(&response, "UUID(%s) NAME(%s) DESCRIPTION(%s)\n",
        uuid_str, channel->data.name, channel->data.description);
    }
    return response;
}

static response_data list_thread(struct client_entry *client)
{
    struct thread_entry *thread;
    response_data response = create_temp_response(OK);
    char uuid_str[UUID_STR_LEN];
    char user_uuid_str[UUID_STR_LEN];

    SLIST_FOREACH(thread, &client->data.channel->data.thread_head, entries) {
        uuid_unparse(thread->data.uuid, uuid_str);
        uuid_unparse(thread->data.author_uuid, user_uuid_str);
        append_data(&response,
        "UUID(%s) AUTHOR_UUID(%s) TIME(%ld) NAME(%s) BODY(%s)\n",
        uuid_str, user_uuid_str, thread->data.time,
        thread->data.name, thread->data.message);
    }
    return response;
}

static response_data list_replies(struct client_entry *client)
{
    struct text_entry *text;
    response_data response = create_temp_response(OK);
    char uuid_str[UUID_STR_LEN];
    char user_uuid_str[UUID_STR_LEN];

    TAILQ_FOREACH_REVERSE(text, &client->data.thread->data.text_head,
    text_head, entries) {
        uuid_unparse(client->data.thread->data.uuid, uuid_str);
        uuid_unparse(text->data.author_uuid, user_uuid_str);
        append_data(&response,
        "UUID(%s) AUTHOR_UUID(%s) TIME(%ld) BODY(%s)\n",
        uuid_str, user_uuid_str, text->data.time, text->data.text);
    }
    return response;
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data list_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    enum use_state state = get_use_state(client);
    response_data response;

    switch (state) {
        case USE_NONE:
            response = list_team(manager);
            break;
        case USE_TEAM:
            response = list_channel(client);
            break;
        case USE_CHANNEL:
            response = list_thread(client);
            break;
        case USE_THREAD:
            response = list_replies(client);
            break;
        default:
            response = create_response(KO, "Invalid usage of /use.");
            break;
    }
    return response;
}
#pragma GCC diagnostic error "-Wunused-parameter"