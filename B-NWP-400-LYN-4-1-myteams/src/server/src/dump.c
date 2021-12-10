/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** deconstructor
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "struct.h"

static void dump_users(FILE *stream, client_manager *manager)
{
    struct user_entry *user;
    char uuid[UUID_STR_LEN] = {0};

    SLIST_FOREACH(user, &manager->user_head, entries) {
        uuid_unparse(user->data.uuid, uuid);
        fprintf(stream, "USER\n%s\n%s\n", user->data.name, uuid);
    }
}

static void dump_conversations(FILE *stream, client_manager *manager)
{
    entry_context ctx;

    SLIST_FOREACH(ctx.conversation, &manager->conversation_head, entries) {
        fprintf(stream, "CONVERSATION\n%s\n%s\n",
        ctx.conversation->data.name0, ctx.conversation->data.name1);
        TAILQ_FOREACH(ctx.text, &ctx.conversation->data.text_head, entries) {
            uuid_unparse(ctx.text->data.author_uuid, ctx.uuid_str);
            fprintf(stream, "TEXT\n%s\n%s\n%ld\n", ctx.text->data.text,
            ctx.uuid_str, ctx.text->data.time);
        }
    }
}

static void dump_threads(
    FILE *stream, entry_context *ctx)
{
    char uuid_str[UUID_STR_LEN];
    char user_uuid_str[UUID_STR_LEN];

    SLIST_FOREACH(ctx->thread, &ctx->channel->data.thread_head, entries) {
        uuid_unparse(ctx->thread->data.uuid, uuid_str);
        uuid_unparse(ctx->thread->data.author_uuid, user_uuid_str);
        fprintf(stream, "THREAD\n%s\n%s\n%s\n%s\n%ld\n",
        ctx->thread->data.name, ctx->thread->data.message, user_uuid_str,
        uuid_str, ctx->thread->data.time);
        TAILQ_FOREACH(ctx->text, &ctx->thread->data.text_head, entries) {
            uuid_unparse(ctx->text->data.author_uuid, ctx->uuid_str);
            fprintf(stream, "TEXT\n%s\n%s\n%ld\n", ctx->text->data.text,
            ctx->uuid_str, ctx->text->data.time);
        }
    }
}

static void dump_teams(FILE *stream, client_manager *manager)
{
    entry_context ctx;

    SLIST_FOREACH(ctx.team, &manager->team_head, entries) {
        uuid_unparse(ctx.team->data.uuid, ctx.uuid_str);
        fprintf(stream, "TEAM\n%s\n%s\n%s\n",
        ctx.team->data.name, ctx.team->data.description, ctx.uuid_str);
        SLIST_FOREACH(ctx.user_ptr, &ctx.team->data.subscribed_head, entries) {
            uuid_unparse(ctx.user_ptr->data.user->data.uuid, ctx.uuid_str);
            fprintf(stream, "SUBSCRIBE\n%s\n", ctx.uuid_str);
        }
        SLIST_FOREACH(ctx.channel, &ctx.team->data.channel_head, entries) {
            uuid_unparse(ctx.channel->data.uuid, ctx.uuid_str);
            fprintf(stream, "CHANNEL\n%s\n%s\n%s\n", ctx.channel->data.name,
            ctx.channel->data.description, ctx.uuid_str);
            dump_threads(stream, &ctx);
        }
    }
}

void dump_manager(client_manager *manager)
{
    FILE *stream = fopen("manager_data.txt", "w");

    if (stream != NULL) {
        dump_users(stream, manager);
        dump_conversations(stream, manager);
        dump_teams(stream, manager);
    } else {
        printf("Error while dumping manager data.\n");
    }
}
