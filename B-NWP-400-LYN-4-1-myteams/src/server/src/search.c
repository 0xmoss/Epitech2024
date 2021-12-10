/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** search
*/

#include <string.h>
#include "struct.h"

struct user_entry *find_user_by_uuid(
    client_manager *manager, uuid_t uuid)
{
    struct user_entry *user = NULL;
    struct user_entry *user_cursor = NULL;

    SLIST_FOREACH(user_cursor, &manager->user_head, entries) {
        if (!uuid_compare(user_cursor->data.uuid, uuid)) {
            user = user_cursor;
            break;
        }
    }
    return user;
}

struct team_entry *find_team_by_name(
    client_manager *manager, const char *name)
{
    struct team_entry *team = NULL;
    struct team_entry *team_cursor = NULL;

    SLIST_FOREACH(team_cursor, &manager->team_head, entries) {
        if (!strcmp(team_cursor->data.name, name)) {
            team = team_cursor;
            break;
        }
    }
    return team;
}

struct team_entry *find_team_by_uuid(client_manager *manager, uuid_t uuid)
{
    struct team_entry *team = NULL;
    struct team_entry *team_cursor = NULL;

    SLIST_FOREACH(team_cursor, &manager->team_head, entries) {
        if (!uuid_compare(team_cursor->data.uuid, uuid)) {
            team = team_cursor;
            break;
        }
    }
    return team;
}

struct channel_entry *find_channel_by_name(
    struct team_entry *team, const char *name)
{
    struct channel_entry *channel = NULL;
    struct channel_entry *channel_cursor = NULL;

    SLIST_FOREACH(channel_cursor, &team->data.channel_head, entries) {
        if (!strcmp(channel_cursor->data.name, name)) {
            channel = channel_cursor;
            break;
        }
    }
    return channel;
}

struct channel_entry *find_channel_by_uuid(
    struct team_entry *team, uuid_t uuid)
{
    struct channel_entry *channel = NULL;
    struct channel_entry *channel_cursor = NULL;

    SLIST_FOREACH(channel_cursor, &team->data.channel_head, entries) {
        if (!uuid_compare(channel_cursor->data.uuid, uuid)) {
            channel = channel_cursor;
            break;
        }
    }
    return channel;
}
