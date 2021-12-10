/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** global_struct
*/

#pragma once

#include <uuid/uuid.h>
#include "global_define.h"
#include "global_enum.h"

typedef struct response_data {
    response_code code;
    size_t size;
    char *message;
} response_data;

typedef struct request_data {
    request_info info;
    char command[COMMAND_STR_LEN];
    char uuid0[UUID_STR_LEN];
    char uuid1[UUID_STR_LEN];
    char uuid2[UUID_STR_LEN];
    char name[NAME_STR_LEN];
    char description[DESCRIPTION_STR_LEN];
    char body[BODY_STR_LEN];
} request_data;
