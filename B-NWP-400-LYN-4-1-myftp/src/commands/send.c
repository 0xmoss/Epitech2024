/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myftp-
** File description:
** send.c
*/

#include "send.h"

#include "phaseout.h"

#include "build.h"
#include "socket.h"

size_t send_to_client(server_t *server, char *buffer)
{
    write(server->guard, buffer, phase_length(buffer, EMPTY));

    return (True);
}
