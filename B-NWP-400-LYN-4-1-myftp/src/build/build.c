/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** self.c
*/

#include "build.h"

#include "phaseout.h"

#include "socket.h"

self_t *build_self(void)
{
    self_t *data = malloc(sizeof(self_t));

    data->s_port = False;
    data->s_path = False;
    data->s_help = False;
    data->port = phase_set("_EMPTY_\0", EMPTY);
    data->path = phase_set("_EMPTY_\0", EMPTY);
    data->max = PATH_MAX;

    return (data);
}

server_t *build_server(void)
{
    server_t *data = malloc(sizeof(server_t));

    data->domain = AF_INET;
    data->type = SOCK_STREAM;
    data->protocol = 0;
    data->limit = 0;
    data->bind = 0;
    data->socket = 0;
    data->guard = 0;
    data->user = phase_set("_EMPTY_\0", EMPTY);
    data->pass = phase_set("_EMPTY_\0", EMPTY);
    data->active = False;
    data->passive = False;

    return (data);
}
