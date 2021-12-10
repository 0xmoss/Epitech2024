/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** search2
*/

#include <string.h>
#include "struct.h"

struct thread_entry *find_thread_by_name(
    struct channel_entry *channel, const char *name)
{
    struct thread_entry *thread = NULL;
    struct thread_entry *thread_cursor = NULL;

    SLIST_FOREACH(thread_cursor, &channel->data.thread_head, entries) {
        if (!strcmp(thread_cursor->data.name, name)) {
            thread = thread_cursor;
            break;
        }
    }
    return thread;
}

struct thread_entry *find_thread_by_uuid(
    struct channel_entry *channel, uuid_t uuid)
{
    struct thread_entry *thread = NULL;
    struct thread_entry *thread_cursor = NULL;

    SLIST_FOREACH(thread_cursor, &channel->data.thread_head, entries) {
        if (!uuid_compare(thread_cursor->data.uuid, uuid)) {
            thread = thread_cursor;
            break;
        }
    }
    return thread;
}

struct user_ptr_entry *find_subscribed_user_by_name(
    struct team_entry *team, const char *name)
{
    struct user_ptr_entry *user_ptr = NULL;
    struct user_ptr_entry *user_ptr_cursor = NULL;

    SLIST_FOREACH(user_ptr_cursor, &team->data.subscribed_head, entries) {
        if (!strcmp(user_ptr_cursor->data.user->data.name, name)) {
            user_ptr = user_ptr_cursor;
            break;
        }
    }
    return user_ptr;
}

struct user_ptr_entry *find_subscribed_user_by_uuid(
    struct team_entry *team, uuid_t uuid)
{
    struct user_ptr_entry *user_ptr = NULL;
    struct user_ptr_entry *user_ptr_cursor = NULL;

    SLIST_FOREACH(user_ptr_cursor, &team->data.subscribed_head, entries) {
        if (!uuid_compare(user_ptr_cursor->data.user->data.uuid, uuid)) {
            user_ptr = user_ptr_cursor;
            break;
        }
    }
    return user_ptr;
}

struct team_ptr_entry *find_subscribed_team_by_uuid(
    struct user_entry *user, uuid_t uuid)
{
    struct team_ptr_entry *team_ptr = NULL;
    struct team_ptr_entry *team_ptr_cursor = NULL;

    SLIST_FOREACH(team_ptr_cursor, &user->data.subscribed_head, entries) {
        if (!uuid_compare(team_ptr_cursor->data.team->data.uuid, uuid)) {
            team_ptr = team_ptr_cursor;
            break;
        }
    }
    return team_ptr;
}
