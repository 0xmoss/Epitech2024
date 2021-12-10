/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** use
*/

#include "struct.h"
#include "prototypes.h"

static response_data use_thread(
    entry_context *ctx, struct client_entry *client, request_data *data)
{
    if (data->info & UUID2) {
        uuid_parse(data->uuid2, ctx->uuid);
        ctx->thread = find_thread_by_uuid(ctx->channel, ctx->uuid);
        if (ctx->thread != NULL) {
            client->data.team = ctx->team;
            client->data.channel = ctx->channel;
            client->data.thread = ctx->thread;
            return create_response(OK, "Context changed successfully.");
        } else {
            return create_response(KO,
            "Thread with UUID(%s) doesn't exist.", data->uuid2);
        }
    } else {
        client->data.team = ctx->team;
        client->data.channel = ctx->channel;
    }
    return create_response(OK, "Context changed successfully.");
}

static response_data use_channel(
    entry_context *ctx, struct client_entry *client, request_data *data)
{
    if (data->info & UUID1) {
        uuid_parse(data->uuid1, ctx->uuid);
        ctx->channel = find_channel_by_uuid(ctx->team, ctx->uuid);
        if (ctx->channel != NULL) {
            return use_thread(ctx, client, data);
        } else {
            return create_response(KO,
            "Channel with UUID(%s) doesn't exist.", data->uuid1);
        }
    } else {
        client->data.team = ctx->team;
    }
    return create_response(OK, "Context changed successfully.");
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data use_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    entry_context ctx;

    if (data->info & UUID0) {
        uuid_parse(data->uuid0, ctx.uuid);
        ctx.team = find_team_by_uuid(manager, ctx.uuid);
        if (ctx.team != NULL) {
            return use_channel(&ctx, client, data);
        } else {
            return create_response(KO,
            "Team with UUID(%s) doesn't exist.", data->uuid0);
        }
    }
    return create_response(OK, "No context provided.");
}
#pragma GCC diagnostic error "-Wunused-parameter"