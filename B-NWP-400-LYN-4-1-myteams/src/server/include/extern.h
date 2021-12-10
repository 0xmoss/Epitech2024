/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** extern
*/

#pragma once

#include "struct.h"
#include "define.h"

extern response_data (*COMMAND_FUNCS[COMMANDS_NUMBER])(
    client_manager *manager, struct client_entry *client, request_data *data);

extern const bool COMMAND_AUTH_REQUIRE[COMMANDS_NUMBER];

extern const char COMMAND_NAMES[COMMANDS_NUMBER][MAX_COMMAND_LENGTH];

extern const char HELP_COMMAND[];

extern int global_eventfd;