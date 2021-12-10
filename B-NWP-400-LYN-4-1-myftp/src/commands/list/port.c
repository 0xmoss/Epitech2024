/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "port.h"

#include "phaseout.h"

#include "build.h"
#include "send.h"

size_t PORT(server_t *server, char **data)
{
    server->active = True;
    server->passive = False;
    if (phase_llength(data, NULL) == 2) {
        send_to_client(server, "200 Active mode enable host-port: \0");
        send_to_client(server, data[1]);
        send_to_client(server, "\n\0");
        return (True);
    }
    send_to_client(server, "xxx PORT <SP> <host-port> <CRLF>\n\0");

    return (True);
}
