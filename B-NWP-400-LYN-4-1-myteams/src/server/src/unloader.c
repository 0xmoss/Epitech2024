/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** unloader
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "struct.h"
#include "prototypes.h"

static void unload_users(client_manager *manager)
{
    struct user_entry *user;
    struct team_ptr_entry *team_ptr;

    while (!SLIST_EMPTY(&manager->user_head)) {
        user = SLIST_FIRST(&manager->user_head);
        while (!SLIST_EMPTY(&user->data.subscribed_head)) {
            team_ptr = SLIST_FIRST(&user->data.subscribed_head);
            SLIST_REMOVE_HEAD(&user->data.subscribed_head, entries);
            free(team_ptr);
        }
        SLIST_REMOVE_HEAD(&manager->user_head, entries);
        free(user);
    }
}

static void unload_conversations(client_manager *manager)
{
    struct conversation_entry *conversation;
    struct text_entry *text;
    struct text_entry *tmp;

    while (!SLIST_EMPTY(&manager->conversation_head)) {
        conversation = SLIST_FIRST(&manager->conversation_head);
        text = TAILQ_FIRST(&conversation->data.text_head);
        while (text != NULL) {
            tmp = TAILQ_NEXT(text, entries);
            free(text);
            text = tmp;
        }
        SLIST_REMOVE_HEAD(&manager->conversation_head, entries);
        free(conversation);
    }
}

static void unload_threads(entry_context *ctx)
{
    struct text_entry *tmp;

    while (!SLIST_EMPTY(&ctx->channel->data.thread_head)) {
        ctx->thread = SLIST_FIRST(&ctx->channel->data.thread_head);
        ctx->text = TAILQ_FIRST(&ctx->thread->data.text_head);
        while (ctx->text != NULL) {
            tmp = TAILQ_NEXT(ctx->text, entries);
            free(ctx->text);
            ctx->text = tmp;
        }
        SLIST_REMOVE_HEAD(&ctx->channel->data.thread_head, entries);
        free(ctx->thread);
    }
}

static void unload_teams(client_manager *manager)
{
    entry_context ctx;

    while (!SLIST_EMPTY(&manager->team_head)) {
        ctx.team = SLIST_FIRST(&manager->team_head);
        while (!SLIST_EMPTY(&ctx.team->data.subscribed_head)) {
            ctx.user_ptr = SLIST_FIRST(&ctx.team->data.subscribed_head);
            SLIST_REMOVE_HEAD(&ctx.team->data.subscribed_head, entries);
            free(ctx.user_ptr);
        }
        while (!SLIST_EMPTY(&ctx.team->data.channel_head)) {
            ctx.channel = SLIST_FIRST(&ctx.team->data.channel_head);
            unload_threads(&ctx);
            SLIST_REMOVE_HEAD(&ctx.team->data.channel_head, entries);
            free(ctx.channel);
        }
        SLIST_REMOVE_HEAD(&manager->team_head, entries);
        free(ctx.team);
    }
}

void unload_manager(client_manager *manager)
{
    struct client_entry *client;

    unload_users(manager);
    unload_conversations(manager);
    unload_teams(manager);
    while (!SLIST_EMPTY(&manager->client_head)) {
        client = SLIST_FIRST(&manager->client_head);
        SLIST_REMOVE_HEAD(&manager->client_head, entries);
        delete_client(client);
    }
}