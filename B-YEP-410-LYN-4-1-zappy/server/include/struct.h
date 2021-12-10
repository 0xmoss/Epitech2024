/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** struct
*/

#pragma once

#include <stdint.h>
#include <sys/queue.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include "define.h"

typedef struct pos_t {
    ssize_t x;
    ssize_t y;
} pos_t;

typedef enum orientation_t {
    N = 1,
    E = 2,
    S = 3,
    W = 4
} orientation_t;

typedef struct rscount_t {
    size_t food;
    size_t linemate;
    size_t deraumere;
    size_t sibur;
    size_t mendiane;
    size_t phiras;
    size_t thystame;
} rscount_t;

typedef struct ai_data {
    bool from_egg;
    size_t time_unit_life;
    orientation_t orientation;
    size_t elevation;
    pos_t pos;
    size_t waiting_for;
    bool will_execute;
    rscount_t inventory;
    size_t team_id;
    size_t number;
    char requests[MAX_REQUEST][REQUEST_SIZE];
    size_t request_in_queue;
    int ai_socket;
} ai_data;

typedef struct ai_entry {
    ai_data data;
    SLIST_ENTRY(ai_entry) entries;
} ai_entry;

typedef struct ai_ptr_data {
    ai_entry *ai;
} ai_ptr_data;

typedef struct ai_ptr_entry {
    ai_ptr_data data;
    SLIST_ENTRY(ai_ptr_entry) entries;
} ai_ptr_entry;

typedef struct egg_data {
    size_t hatching_in;
    pos_t pos;
    size_t number;
    orientation_t orientation;
} egg_data;

typedef struct egg_entry {
    egg_data data;
    SLIST_ENTRY(egg_entry) entries;
} egg_entry;

typedef struct team_data {
    SLIST_HEAD(ai_ptr_head, ai_ptr_entry) ai_ptr_head;
    SLIST_HEAD(egg_head, egg_entry) egg_head;
    char *name;
    size_t connected;
    size_t max_connected;
} team_data;

typedef enum object_type_t {
    UNDEFINED = -1,
    PLAYER,
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
} object_type_t;

typedef union object_info_t {
    ai_ptr_entry *ai_ptr;
} object_info_t;

typedef struct object_data {
    object_type_t type;
    object_info_t data;
} object_data;

typedef struct object_entry {
    object_data data;
    SLIST_ENTRY(object_entry) entries;
} object_entry;

typedef struct symdata_t {
    SLIST_HEAD(object_head, object_entry) *map;
    size_t count[THYSTAME];
    size_t limit[THYSTAME];
    uint16_t port;
    size_t width;
    size_t height;
    team_data *teams;
    size_t max_client_per_team;
    size_t time_unit_reciprocal;
    size_t time_unit_passed;
} symdata_t;

typedef struct gui_data {
    int gui_socket;
} gui_data;

typedef struct gui_entry {
    gui_data data;
    SLIST_ENTRY(gui_entry) entries;
} gui_entry;

typedef struct client_data {
    int client_socket;
} client_data;

typedef struct client_entry {
    client_data data;
    SLIST_ENTRY(client_entry) entries;
} client_entry;

typedef struct client_manager {
    SLIST_HEAD(ai_head, ai_entry) ai_head;
    SLIST_HEAD(gui_head, gui_entry) gui_head;
    SLIST_HEAD(client_head, client_entry) client_head;
    symdata_t *symdata;
} client_manager;

typedef union conn_t {
    ai_entry *ai;
    gui_entry *gui;
    client_entry *client;
} conn_t;

typedef struct conns_t {
    ai_entry *ai;
    gui_entry *gui;
    client_entry *client;
} conns_t;