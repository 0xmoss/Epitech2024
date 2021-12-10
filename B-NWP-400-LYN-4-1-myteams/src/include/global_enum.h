/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** global_enum
*/

#pragma once

typedef enum response_code {
    OK = 100,
    KO = 200,
    NOT_IMPLEMENTED = 201,
    UNKNOWN_COMMAND = 202,
    INVALID_REQUEST = 203,
    MESSAGE_RECEIVE = 300
} response_code;

typedef enum request_info {
    NONE = 0,
    UUID0 = 1,
    UUID1 = 2,
    UUID2 = 4,
    NAME = 8,
    DESCRIPTION = 16,
    BODY = 32,
    BAD_REQUEST = 64
} request_info;