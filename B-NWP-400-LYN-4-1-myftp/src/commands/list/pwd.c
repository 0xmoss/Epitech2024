/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "pwd.h"

#include "phaseout.h"

#include "build.h"
#include "send.h"

size_t PWD(server_t *server, char **data)
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        send_to_client(server, "257 ");
        send_to_client(server, cwd);
        send_to_client(server, "\n");
    } else
        send_to_client(server, "xxx ERROR\n");

    return (True);
}
