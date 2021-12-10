/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** global_define
*/

#pragma once

#include <uuid/uuid.h>

#define MAX_COMMAND_LENGTH 32
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512
#define MAX_UUID_LENGTH (UUID_STR_LEN - 1)

#define COMMAND_STR_LEN (MAX_COMMAND_LENGTH + 1)
#define NAME_STR_LEN (MAX_NAME_LENGTH + 1)
#define DESCRIPTION_STR_LEN (MAX_DESCRIPTION_LENGTH + 1)
#define BODY_STR_LEN (MAX_BODY_LENGTH + 1)