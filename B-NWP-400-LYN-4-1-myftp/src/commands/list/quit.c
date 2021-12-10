/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "quit.h"

#include "phaseout.h"

#include "build.h"
#include "send.h"

size_t QUIT(server_t *server, char **data)
{
    send_to_client(server, "221\n");
    close(server->guard);

    return (False);
}
