/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "stor.h"

#include "phaseout.h"

#include "build.h"
#include "send.h"

size_t STOR(server_t *server, char **data)
{
    if (access(data[1], F_OK) == 0) {
        printf("Client is uploading: %s\n", data[1]);
    } else {
        send_to_client(server, "226 File not found\n");
    }

    return (True);
}

