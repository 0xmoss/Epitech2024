/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "noop.h"

#include "phaseout.h"

#include "build.h"
#include "send.h"

size_t NOOP(server_t *server, char **data)
{
    if (phase_equals(data[0], "NOOP\0", EMPTY) == True)
        send_to_client(server, "200\n");
    else
        send_to_client(server, "500\n");

    return (True);
}
