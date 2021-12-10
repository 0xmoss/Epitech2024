/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "pass.h"

#include "phaseout.h"

#include "build.h"
#include "send.h"

size_t PASS(server_t *server, char **data)
{
    printf("'%s'\n", server->user);
    if (phase_equals(server->user, "Anonymous\0", EMPTY) != True) {
        if (phase_llength(data, NULL) < 2) {
            send_to_client(server, "PASS <PASSWORD>\n\0");
            return (True);
        }
        if (phase_equals(server->user, "_EMPTY_\0", EMPTY) != True) {
            server->pass = data[1];
            send_to_client(server, "230 User logged in, proceed.\n\0");
        } else
            send_to_client(server, "xxx You must enter a USER first.\n\0");
    }
    send_to_client(server, "230 User logged in, proceed.\n\0");

    return (True);
}
