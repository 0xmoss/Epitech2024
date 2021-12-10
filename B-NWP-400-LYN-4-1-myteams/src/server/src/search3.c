/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** search3
*/

#include <string.h>
#include "struct.h"

struct team_ptr_entry *find_subscribed_team_by_name(
    struct user_entry *user, char const *name)
{
    struct team_ptr_entry *team_ptr = NULL;
    struct team_ptr_entry *team_ptr_cursor = NULL;

    SLIST_FOREACH(team_ptr_cursor, &user->data.subscribed_head, entries) {
        if (!strcmp(team_ptr_cursor->data.team->data.name, name)) {
            team_ptr = team_ptr_cursor;
            break;
        }
    }
    return team_ptr;
}

struct conversation_entry *find_conversation_by_name(
    client_manager *manager, char const *name0, char const *name1)
{
    struct conversation_entry *conversation = NULL;
    struct conversation_entry *conversation_cursor = NULL;

    SLIST_FOREACH(conversation_cursor, &manager->conversation_head, entries) {
        if ((!strcmp(conversation_cursor->data.name0, name0) &&
            !strcmp(conversation_cursor->data.name1, name1)) ||
            (!strcmp(conversation_cursor->data.name1, name1) &&
            !strcmp(conversation_cursor->data.name0, name0))) {
            conversation = conversation_cursor;
            break;
        }
    }
    return conversation;
}
