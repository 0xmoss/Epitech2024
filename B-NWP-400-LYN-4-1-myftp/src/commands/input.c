/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "input.h"

#include "phaseout.h"

#include "build.h"
#include "socket.h"

#include "help.h"
#include "quit.h"
#include "user.h"
#include "pass.h"
#include "pwd.h"
#include "cwd.h"
#include "pasv.h"
#include "port.h"
#include "stor.h"
#include "list.h"
#include "noop.h"

size_t id(char *function_name)
{
    char *ids = phase_set(
        "HELP|QUIT|USER|PASS|PWD|CWD|PASV|PORT|STOR|LIST|NOOP\0",
        EMPTY);
    char **ids_d = phase_split(ids, '|', EMPTY, NULL);

    for (size_t i = 0; ids_d[i] != NULL; i++) {
        if (phase_equals(function_name, ids_d[i], EMPTY) == True)
            return (i);
    }

    return (phase_llength(ids_d, NULL) - 1);
}

size_t commands(server_t *server, char **data)
{
    commands_t list[] = {
        {HELP},
        {QUIT},
        {USER},
        {PASS},
        {PWD},
        {CWD},
        {PASV},
        {PORT},
        {STOR},
        {LIST},
        {NOOP}
    };

    return (list[id(data[0])].command(server, data));
}

size_t parse_input(self_t *self, server_t *server, char **commands_d)
{
    char **clean = phase_mmalloc(phase_llength(commands_d, NULL), NULL);

    for (size_t i = 0; i < phase_llength(commands_d, NULL); i++)
        clean[i] = phase_purge(commands_d[i], '\n', EMPTY);
    for (size_t i = 0; i < phase_llength(clean, NULL); i++)
        clean[i] = phase_purge(clean[i], '\r', EMPTY);

    return (commands(server, clean));
}

size_t input(self_t *self, server_t *server)
{
    char buffer[self->max];
    char **command = NULL;
    size_t retype = True;

    bzero(buffer, self->max);
    read(server->guard, buffer, sizeof(buffer));
    if (phase_contains(buffer, ' ', EMPTY) == True &&
        phase_count(buffer, ' ', '\n') < phase_length(buffer, '\n'))
        command = phase_split(buffer, ' ', EMPTY, NULL);
    else {
        command = phase_mmalloc(1, NULL);
        command[0] = phase_set(buffer, EMPTY);
    }
    retype = parse_input(self, server, command);
    bzero(buffer, self->max);
    phase_ffree(command, NULL);

    return (retype);
}

