/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "pasv.h"

#include "phaseout.h"

#include "build.h"
#include "send.h"

size_t PASV(server_t *server, char **data)
{
    server->active = False;
    server->passive = True;
    send_to_client(server, "200 Passive mode enabled\n\0");

    return (True);
}
