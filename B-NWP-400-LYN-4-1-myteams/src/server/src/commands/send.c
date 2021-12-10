/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** send
*/

#include <time.h>
#include <string.h>
#include "struct.h"
#include "prototypes.h"
#include "logging_server.h"

static void init_conversation(
    client_manager *manager, struct user_entry *source,
    struct user_entry *target, request_data *data)
{
    struct text_entry *text = malloc(sizeof(struct text_entry));
    struct conversation_entry *conversation;
    char uuid_str[2][UUID_STR_LEN];

    conversation = find_conversation_by_name(manager,
    source->data.name, target->data.name);
    text->data.time = time(NULL);
    uuid_copy(text->data.author_uuid, source->data.uuid);
    strcpy(text->data.text, data->body);
    if (conversation == NULL) {
        conversation = malloc(sizeof(struct conversation_entry));
        strcpy(conversation->data.name0, source->data.name);
        strcpy(conversation->data.name1, target->data.name);
        TAILQ_INIT(&conversation->data.text_head);
        SLIST_INSERT_HEAD(&manager->conversation_head, conversation, entries);
    }
    TAILQ_INSERT_HEAD(&conversation->data.text_head, text, entries);
    uuid_unparse(source->data.uuid, uuid_str[0]);
    uuid_unparse(target->data.uuid, uuid_str[1]);
    server_event_private_message_sended(uuid_str[0], uuid_str[1],
    text->data.text);
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data send_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    uuid_t uuid;
    char uuid_str[UUID_STR_LEN];
    struct client_entry *client_entry;
    struct user_entry *user;

    uuid_unparse(client->data.user->data.uuid, uuid_str);
    uuid_parse(data->uuid0, uuid);
    user = find_user_by_uuid(manager, uuid);
    client_entry = find_client_by_uuid(manager, uuid);
    if (user != NULL) {
        if (client_entry != NULL) {
            if (uuid_compare(client->data.user->data.uuid, user->data.uuid))
                send_data_to_client(client_entry, create_response(MESSAGE_RECEIVE,
                "New message from UUID(%s) BODY(%s)", uuid_str, data->body), true);
            init_conversation(manager, client->data.user, user, data);
            return create_response(OK, "The message has been send.");
        } else {
            init_conversation(manager, client->data.user, user, data);
            return create_response(OK, "This user is not connected.");
        }
    } else
        return create_response(KO, "This user does not exist.");
}
#pragma GCC diagnostic error "-Wunused-parameter"