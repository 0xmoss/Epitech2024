/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "cwd.h"

#include "phaseout.h"

#include "build.h"
#include "send.h"

size_t CWD(server_t *server, char **data)
{
    if (phase_llength(data, NULL) == 2) {
        send_to_client(server, "250 ");
        if (chdir(data[1]) == -1) {
            send_to_client(server, "No such file or directory\n");
            return (True);
        }
        send_to_client(server, data[1]);
        send_to_client(server, "\n");
    }

    return (True);
}
