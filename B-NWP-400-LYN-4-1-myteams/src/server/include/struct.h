/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** struct
*/

#pragma once

#include <uuid/uuid.h>
#include <sys/queue.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "define.h"
#include "global_define.h"
#include "global_enum.h"
#include "global_struct.h"

typedef struct client_data {
    struct user_entry *user;
    struct team_entry *team;
    struct channel_entry *channel;
    struct thread_entry *thread;
    int client_socket;
} client_data;

struct client_entry {
    client_data data;
    SLIST_ENTRY(client_entry) entries;
};

typedef struct text_data {
    char text[BODY_STR_LEN];
    uuid_t author_uuid;
    time_t time;
} text_data;


struct text_entry {
    text_data data;
    TAILQ_ENTRY(text_entry) entries;
};

TAILQ_HEAD(text_head, text_entry);

typedef struct conversation_data {
    char name0[NAME_STR_LEN];
    char name1[NAME_STR_LEN];
    struct text_head text_head;
} conversation_data;

struct conversation_entry {
    conversation_data data;
    SLIST_ENTRY(conversation_entry) entries;
};

typedef struct thread_data {
    char name[NAME_STR_LEN];
    char message[BODY_STR_LEN];
    uuid_t author_uuid;
    uuid_t uuid;
    time_t time;
    struct text_head text_head;
} thread_data;

struct thread_entry {
    thread_data data;
    SLIST_ENTRY(thread_entry) entries;
};

typedef struct channel_data {
    char name[NAME_STR_LEN];
    char description[DESCRIPTION_STR_LEN];
    uuid_t uuid;
    SLIST_HEAD(thread_head, thread_entry) thread_head;
} channel_data;

struct channel_entry {
    channel_data data;
    SLIST_ENTRY(channel_entry) entries;
};

typedef struct user_ptr_data {
    struct user_entry *user;
} user_ptr_data;

struct user_ptr_entry {
    user_ptr_data data;
    SLIST_ENTRY(user_ptr_entry) entries;
};

typedef struct team_ptr_data {
    struct team_entry *team;
} team_ptr_data;

struct team_ptr_entry {
    team_ptr_data data;
    SLIST_ENTRY(team_ptr_entry) entries;
};

typedef struct team_data {
    char name[NAME_STR_LEN];
    char description[DESCRIPTION_STR_LEN];
    uuid_t uuid;
    SLIST_HEAD(subscribed_head, user_ptr_entry) subscribed_head;
    SLIST_HEAD(channel_head, channel_entry) channel_head;
} team_data;

struct team_entry {
    team_data data;
    SLIST_ENTRY(team_entry) entries;
};

typedef struct user_data {
    char name[NAME_STR_LEN];
    uuid_t uuid;
    bool connected;
    SLIST_HEAD(subscribed_head_user, team_ptr_entry) subscribed_head;
} user_data;

struct user_entry {
    user_data data;
    SLIST_ENTRY(user_entry) entries;
};

typedef struct entry_context {
    FILE *stream;
    bool conversation_mode;
    struct user_entry *user;
    struct conversation_entry *conversation;
    struct text_entry *text;
    struct team_entry *team;
    struct channel_entry *channel;
    struct thread_entry *thread;
    struct user_ptr_entry *user_ptr;
    struct team_ptr_entry *team_ptr;
    uuid_t uuid;
    char uuid_str[UUID_STR_LEN];
} entry_context;

typedef struct client_manager {
    SLIST_HEAD(client_head, client_entry) client_head;
    SLIST_HEAD(conversation_head, conversation_entry) conversation_head;
    SLIST_HEAD(user_head, user_entry) user_head;
    SLIST_HEAD(team_head, team_entry) team_head;
} client_manager;
