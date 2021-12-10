/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** unsubscribe
*/

#include "struct.h"
#include "prototypes.h"
#include "logging_server.h"

static void unsubscribe_action(struct client_entry *client, entry_context *ctx)
{
    char team_uuid_str[UUID_STR_LEN];
    char user_uuid_str[UUID_STR_LEN];

    uuid_unparse(ctx->team->data.uuid, team_uuid_str);
    uuid_unparse(client->data.user->data.uuid, user_uuid_str);
    server_event_user_unsubscribed(team_uuid_str, user_uuid_str);
    SLIST_REMOVE(&ctx->team->data.subscribed_head, ctx->user_ptr,
    user_ptr_entry, entries);
    SLIST_REMOVE(&client->data.user->data.subscribed_head,
    ctx->team_ptr, team_ptr_entry, entries);
    free(ctx->team_ptr);
    free(ctx->user_ptr);
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data unsubscribe_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    entry_context ctx;

    uuid_parse(data->uuid0, ctx.uuid);
    if ((ctx.team = find_team_by_uuid(manager, ctx.uuid)) != NULL) {
        ctx.team_ptr = find_subscribed_team_by_uuid(
            client->data.user, ctx.uuid);
        if (ctx.team_ptr != NULL) {
            ctx.user_ptr = find_subscribed_user_by_uuid(ctx.team,
            client->data.user->data.uuid);
            unsubscribe_action(client, &ctx);
            return create_response(OK,
            "You were unsubscribed from this team.");
        } else {
            return create_response(OK,
            "You weren't subscribed from this team.");
        }
    } else {
        return create_response(KO, "This team doesn't exist.");
    }
}
#pragma GCC diagnostic error "-Wunused-parameter"