/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** loader
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "prototypes.h"
#include "logging_server.h"

static void load_manager_type_last_fallback(
    char const *type, entry_context *ctx, client_manager *manager)
{
    if (!strcmp(type, "USER")) {
        ctx->user = malloc(sizeof(struct user_entry));
        getline_wrapper(ctx->stream, ctx->user->data.name, NAME_STR_LEN,
        ctx->uuid_str, UUID_STR_LEN, NULL);
        uuid_parse(ctx->uuid_str, ctx->user->data.uuid);
        ctx->user->data.connected = false;
        SLIST_INIT(&ctx->user->data.subscribed_head);
        SLIST_INSERT_HEAD(&manager->user_head, ctx->user, entries);
        server_event_user_loaded(ctx->uuid_str, ctx->user->data.name);
    } else if (!strcmp(type, "SUBSCRIBE")) {
        ctx->user_ptr = malloc(sizeof(struct user_ptr_entry));
        ctx->team_ptr = malloc(sizeof(struct team_ptr_entry));
        getline_wrapper(ctx->stream, ctx->uuid_str, UUID_STR_LEN, NULL);
        uuid_parse(ctx->uuid_str, ctx->uuid);
        ctx->user_ptr->data.user = find_user_by_uuid(manager, ctx->uuid);
        ctx->team_ptr->data.team = ctx->team;
        SLIST_INSERT_HEAD(&ctx->team->data.subscribed_head,
        ctx->user_ptr, entries);
        SLIST_INSERT_HEAD(&ctx->user_ptr->data.user->data.subscribed_head,
        ctx->team_ptr, entries);
    }
}

static void load_manager_type_second_fallback(
    char const *type, entry_context *ctx, client_manager *manager)
{
    char time[11] = {0};

    if (!strcmp(type, "TEXT") && ctx->conversation_mode && ctx->conversation) {
        ctx->text = malloc(sizeof(struct text_entry));
        getline_wrapper(ctx->stream, ctx->text->data.text, BODY_STR_LEN,
        ctx->uuid_str, UUID_STR_LEN, time, 10, NULL);
        uuid_parse(ctx->uuid_str, ctx->text->data.author_uuid);
        ctx->text->data.time = atol(time);
        if (ctx->conversation_mode && ctx->conversation) {
            TAILQ_INSERT_HEAD(&ctx->conversation->data.text_head,
            ctx->text, entries);
        } else if (!ctx->conversation_mode && ctx->thread) {
            TAILQ_INSERT_HEAD(&ctx->thread->data.text_head,
            ctx->text, entries);
        }
    } else {
        load_manager_type_last_fallback(type, ctx, manager);
    }
}

static void load_manager_type_fallback(
    char const *type, entry_context *ctx, client_manager *manager)
{
    char user_uuid_str[UUID_STR_LEN];
    char time[11] = {0};

    if (!strcmp(type, "CHANNEL") && ctx->team) {
        ctx->channel = malloc(sizeof(struct channel_entry));
        getline_wrapper(ctx->stream, ctx->channel->data.name, NAME_STR_LEN,
        ctx->channel->data.description, DESCRIPTION_STR_LEN, ctx->uuid_str,
        UUID_STR_LEN, NULL);
        uuid_parse(ctx->uuid_str, ctx->channel->data.uuid);
        SLIST_INIT(&ctx->channel->data.thread_head);
        SLIST_INSERT_HEAD(&ctx->team->data.channel_head,
        ctx->channel, entries);
    } else if (!strcmp(type, "THREAD") && ctx->channel) {
        ctx->thread = malloc(sizeof(struct thread_entry));
        getline_wrapper(ctx->stream, ctx->thread->data.name, NAME_STR_LEN,
        ctx->thread->data.message, BODY_STR_LEN, user_uuid_str,
        UUID_STR_LEN, ctx->uuid_str, UUID_STR_LEN, time, 10, NULL);
        uuid_parse(user_uuid_str, ctx->thread->data.author_uuid);
        uuid_parse(ctx->uuid_str, ctx->thread->data.uuid);
        ctx->thread->data.time = atol(time);
        TAILQ_INIT(&ctx->thread->data.text_head);
        SLIST_INSERT_HEAD(&ctx->channel->data.thread_head,
        ctx->thread, entries);
    } else {
        load_manager_type_second_fallback(type, ctx, manager);
    }
}

static void load_manager_type(
    char const *type, entry_context *ctx, client_manager *manager)
{
    if (!strcmp(type, "CONVERSATION")) {
        ctx->conversation = malloc(sizeof(struct conversation_entry));
        getline_wrapper(ctx->stream, ctx->conversation->data.name0,
        NAME_STR_LEN, ctx->conversation->data.name1, NAME_STR_LEN, NULL);
        TAILQ_INIT(&ctx->conversation->data.text_head);
        SLIST_INSERT_HEAD(&manager->conversation_head,
        ctx->conversation, entries);
        ctx->conversation_mode = true;
    } else if (!strcmp(type, "TEAM")) {
        ctx->team = malloc(sizeof(struct team_entry));
        getline_wrapper(ctx->stream, ctx->team->data.name, NAME_STR_LEN,
        ctx->team->data.description, DESCRIPTION_STR_LEN, ctx->uuid_str,
        UUID_STR_LEN, NULL);
        uuid_parse(ctx->uuid_str, ctx->team->data.uuid);
        SLIST_INIT(&ctx->team->data.subscribed_head);
        SLIST_INIT(&ctx->team->data.channel_head);
        SLIST_INSERT_HEAD(&manager->team_head, ctx->team, entries);
        ctx->conversation_mode = false;
    } else {
        load_manager_type_fallback(type, ctx, manager);
    }
}

client_manager load_manager(void)
{
    FILE *file = fopen("manager_data.txt", "r");
    client_manager manager;
    size_t n = 0;
    ssize_t readsize;
    char *lineptr = NULL;
    entry_context context = {file, EMPTY_CONTEXT};

    SLIST_INIT(&manager.client_head);
    SLIST_INIT(&manager.user_head);
    SLIST_INIT(&manager.team_head);
    SLIST_INIT(&manager.conversation_head);
    if (file != NULL) {
        while ((readsize = getline(&lineptr, &n, file)) > 0) {
            lineptr[readsize - 1] = '\0';
            load_manager_type(lineptr, &context, &manager);
        }
        if (lineptr != NULL)
            free(lineptr);
    }
    return manager;
}
