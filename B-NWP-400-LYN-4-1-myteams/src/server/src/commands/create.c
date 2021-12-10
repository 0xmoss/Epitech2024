/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** create
*/

#include <string.h>
#include "struct.h"
#include "prototypes.h"
#include "logging_server.h"

static response_data create_team(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    struct team_entry *team = malloc(sizeof(struct team_entry));
    char uuid_str[UUID_STR_LEN];
    char uuid_snd_str[UUID_STR_LEN];

    SLIST_INIT(&team->data.channel_head);
    SLIST_INIT(&team->data.subscribed_head);
    uuid_generate(team->data.uuid);
    uuid_unparse(team->data.uuid, uuid_str);
    uuid_unparse(client->data.user->data.uuid, uuid_snd_str);
    strcpy(team->data.name, data->name);
    strcpy(team->data.description, data->description);
    SLIST_INSERT_HEAD(&manager->team_head, team, entries);
    server_event_team_created(uuid_str, data->name, uuid_snd_str);
    return create_response(OK,
    "New team created with UUID(%s) NAME(%s) DESCRIPTION(%s)",
    uuid_str, data->name, data->description);
}

static response_data create_channel(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    struct channel_entry *channel = malloc(sizeof(struct channel_entry));
    struct user_ptr_entry *user_ptr;
    response_data response;
    char uuid_str[2][UUID_STR_LEN];

    SLIST_INIT(&channel->data.thread_head);
    uuid_generate(channel->data.uuid);
    uuid_unparse(channel->data.uuid, uuid_str[0]);
    uuid_unparse(client->data.team->data.uuid, uuid_str[1]);
    strcpy(channel->data.name, data->name);
    strcpy(channel->data.description, data->description);
    SLIST_INSERT_HEAD(&client->data.team->data.channel_head, channel, entries);
    server_event_channel_created(uuid_str[1], uuid_str[0], data->name);
    response = create_response(OK,
    "New channel created with UUID(%s) NAME(%s) DESCRIPTION(%s)",
    uuid_str[0], data->name, data->description);
    SLIST_FOREACH(user_ptr, &client->data.team->data.subscribed_head, entries)
        if (uuid_compare(user_ptr->data.user->data.uuid,
        client->data.user->data.uuid))
            send_data_to_uuid(manager, response,
            user_ptr->data.user->data.uuid, false);
    return response;
}

static response_data create_thread(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    struct thread_entry *thread = malloc(sizeof(struct thread_entry));
    struct user_ptr_entry *ptr;
    response_data response;
    char uuid_str[3][UUID_STR_LEN];

    TAILQ_INIT(&thread->data.text_head);
    thread->data.time = time(NULL);
    uuid_generate(thread->data.uuid);
    uuid_copy(thread->data.author_uuid, client->data.user->data.uuid);
    uuid_unparse(client->data.user->data.uuid, uuid_str[0]);
    uuid_unparse(client->data.channel->data.uuid, uuid_str[1]);
    uuid_unparse(thread->data.uuid, uuid_str[2]);
    strcpy(thread->data.name, data->name);
    strcpy(thread->data.message, data->body);
    SLIST_INSERT_HEAD(&client->data.channel->data.thread_head, thread,entries);
    server_event_thread_created(uuid_str[1], uuid_str[2],
    uuid_str[0], data->name, data->body);
    response = create_response(OK, "New thread created with UUID(%s) "
    "USER_UUID(%s) TIME(%ld) NAME(%s) BODY(%s)",
    uuid_str[2], uuid_str[0], thread->data.time, data->name, data->body);
    SLIST_FOREACH(ptr, &client->data.team->data.subscribed_head, entries)
        if (uuid_compare(ptr->data.user->data.uuid,
        client->data.user->data.uuid))
            send_data_to_uuid(manager, response,
            ptr->data.user->data.uuid, false);
    return response;
}

static response_data create_reply(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    struct text_entry *text = malloc(sizeof(struct text_entry));
    struct user_ptr_entry *ptr;
    response_data response;
    char uuid_str[3][UUID_STR_LEN];

    text->data.time = time(NULL);
    uuid_copy(text->data.author_uuid, client->data.user->data.uuid);
    strcpy(text->data.text, data->body);
    uuid_unparse(client->data.thread->data.uuid, uuid_str[0]);
    uuid_unparse(client->data.user->data.uuid, uuid_str[1]);
    uuid_unparse(client->data.team->data.uuid, uuid_str[2]);
    TAILQ_INSERT_HEAD(&client->data.thread->data.text_head, text, entries);
    server_event_reply_created(uuid_str[0], uuid_str[1], data->body);
    response = create_response(OK, "New reply created with TEAM_UUID(%s) "
    "THREAD_UUID(%s) USER_UUID(%s) TIME(%ld) BODY(%s)",
    uuid_str[2], uuid_str[0], uuid_str[1], text->data.time, data->body);
    SLIST_FOREACH(ptr, &client->data.team->data.subscribed_head, entries)
        if (uuid_compare(ptr->data.user->data.uuid,
        client->data.user->data.uuid))
            send_data_to_uuid(manager, response,
            ptr->data.user->data.uuid, false);
    return response;
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data create_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    enum use_state state = get_use_state(client);
    response_data response;

    switch (state) {
        case USE_NONE:
            response = create_team(manager, client, data);
            break;
        case USE_TEAM:
            response = create_channel(manager, client, data);
            break;
        case USE_CHANNEL:
            response = create_thread(manager, client, data);
            break;
        case USE_THREAD:
            response = create_reply(manager, client, data);
            break;
        default:
            response = create_response(KO, "Invalid usage of /use.");
            break;
    }
    return response;
}
#pragma GCC diagnostic error "-Wunused-parameter"