/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** define
*/

#pragma once

#define REQUEST_SIZE 128
#define MAX_REQUEST 10
#define BUFFER_SIZE 1024

#define PORT_ERROR_STR \
    "-p option only accepts integer values between 0 and 65535"
#define WIDTH_ERROR_STR \
    "-x option only accepts integer values between 10 and 30"
#define HEIGHT_ERROR_STR \
    "-y option only accepts integer values between 10 and 30"
#define NAME_ERROR_STR \
    "-n option only accepts unique team names and not 'GRAPHIC'"
#define MAX_CLIENT_PER_TEAM_ERROR_STR \
    "-c option only accepts integer values greater or equal to 1"
#define FREQ_ERROR_STR \
    "-f option only accepts integer values between 2 and 10000"

#define CLIENT_MANAGER_INITIALIZER(symdata) { SLIST_HEAD_INITIALIZER(), \
    SLIST_HEAD_INITIALIZER(), SLIST_HEAD_INITIALIZER(), symdata }
#define TIMESPEC_INITIALIZER(rtu) { .tv_sec = 0, \
    .tv_nsec = 1000000000 / rtu }
#define SYMDATA_INITIALIZER { \
    .map = NULL, .port = 4242, .width = 10, .height = 10, .teams = NULL, \
    .max_client_per_team = 3, .time_unit_reciprocal = 100, \
    .time_unit_passed = 0, .count = {0, 0, 0, 0, 0, 0, 0} }
#define SOCKADDR_INITIALIZER(port) { \
    .sin_addr.s_addr = INADDR_ANY, \
    .sin_family = AF_INET, \
    .sin_port = htons(port) }
#define CURSOR_INITIALIZER(manager) { \
    .client = SLIST_FIRST(&manager->client_head), \
    .gui = SLIST_FIRST(&manager->gui_head), \
    .ai = SLIST_FIRST(&manager->ai_head) }
#define POS_INITIALIZER(pos) { \
    pos[0].x - pos[1].x, \
    pos[0].y - pos[1].y, \
    pos[1].x - pos[0].x, \
    pos[1].y - pos[0].y }

#define SLIST_DESTROY(var,head,field) \
    while (!SLIST_EMPTY(head)) { \
        var = SLIST_FIRST(head); \
        SLIST_REMOVE_HEAD(head, field); \
        free(var); \
    }
