/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** core.c
*/

#include "core.h"

#include "phaseout.h"

#include "build.h"
#include "help.h"
#include "socket.h"

size_t login(self_t *self)
{
    if (phase_equals(self->path, "Anonymous\0", EMPTY) != True &&
        phase_equals(self->path, "_EMPTY_\0", EMPTY) != True) {
        if (chdir(self->path) != -1) {
            return (True);
        }
        printf("%s: Path not found\n", self->path);
        return (False);
    }
    return (False);
}

size_t core(self_t *self, server_t *server)
{
    if (self->s_help == True)
        return (help());
    login(self);
    create(self, server);
    return (True);
}

size_t arguments(self_t *self, int ac, char **argv)
{
    for (int i = 1; i < ac; i++) {
        if (phase_equals(argv[i], "-help\0", EMPTY) == True ||
            phase_equals(argv[i], "--help\0", EMPTY) == True)
            self->s_help = True;
        if (self->s_port == False) {
            self->s_port = True;
            self->port = argv[i];
        } else if (self->s_path == False && self->s_port == True) {
            self->s_path = True;
            self->path = argv[i];
        }
    }

    return (True);
}

int main(int ac, char **argv)
{
    self_t *self_data = build_self();
    server_t *server_data = build_server();

    if (ac > 1 && ac < 4) {
        arguments(self_data, ac, argv);
        core(self_data, server_data);
        free(self_data);
        free(server_data);
        return (True);
    }

    return (84);
}
