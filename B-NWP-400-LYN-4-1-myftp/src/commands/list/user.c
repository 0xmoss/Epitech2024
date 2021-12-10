/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "user.h"

#include "phaseout.h"

#include "build.h"
#include "send.h"

size_t USER(server_t *server, char **data)
{
    if (phase_equals(server->user, "Anonymous\0", EMPTY) != True) {
        if (phase_llength(data, NULL) == 2) {
            server->user = phase_set(data[1], EMPTY);
            send_to_client(server, "331 User name okay, need passord.\n\0");
            return (True);
        }
        send_to_client(server, "xxx USER <SP> <username> <CRLF>\n\0");
    } else
        send_to_client(server, "331 User name okay, need passord.\n\0");

    return (True);
}
