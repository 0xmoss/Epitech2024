/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** messages
*/

#include "struct.h"
#include "prototypes.h"

static response_data get_messages(struct conversation_entry *conversation,
    struct user_entry *source, struct user_entry *target)
{
    struct text_entry *text;
    response_data response = create_temp_response(OK);

    TAILQ_FOREACH_REVERSE(text, &conversation->data.text_head,
    text_head, entries) {
        if (!uuid_compare(source->data.uuid, text->data.author_uuid)) {
            append_data(&response, "TIME(%ld) UUID(%s) BODY(%s)\n",
            text->data.time, source->data.uuid, text->data.text);
        } else if (!uuid_compare(target->data.uuid, text->data.author_uuid)) {
            append_data(&response, "TIME(%ld) UUID(%s) BODY(%s)\n",
            text->data.time, target->data.uuid, text->data.text);
        }
    }
    return response;
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data messages_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    uuid_t uuid;
    struct conversation_entry *conversation;
    struct user_entry *user;

    uuid_parse(data->uuid0, uuid);
    user = find_user_by_uuid(manager, uuid);
    if (user != NULL) {
        conversation = find_conversation_by_name(manager,
        client->data.user->data.name, user->data.name);
        if (conversation != NULL) {
            return get_messages(conversation, client->data.user, user);
        } else {
            return create_response(OK,
            "You have no active conversation with this user.");
        }
    } else {
        return create_response(KO, "This user does not exist.");
    }
}
#pragma GCC diagnostic error "-Wunused-parameter"