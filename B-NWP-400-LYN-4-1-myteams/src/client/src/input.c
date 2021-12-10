/*
** EPITECH PROJECT, 2020
** teams
** File description:
** input.c
*/

#include "cli.h"
#include "tools.h"
#include "phaseout.h"

static size_t valid(self_t *self, char *buffer)
{
    if (phase_length(buffer, EMPTY) > 2) {
        if (phase_contains(buffer, '/', EMPTY) == True) {
            if (self->login == DISCONNECTED &&
                phase_startswith(buffer, "/login", EMPTY) == False &&
                phase_startswith(buffer, "/help", EMPTY) == False) {
                    client_error_unauthorized();
                    return (False);
                }
            return (True);
        }
    }

    return (False);
}

int input(int master, self_t *self)
{
    char *buff = phase_malloc(BUFFER, EMPTY);
    int n = 0;
    fd_set fds;
    self->master = master;

    for (;; n = 0) {
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(master, &fds);
        if (select(master + 1, &fds, NULL, NULL, NULL) == -1)
            return (-1);
        if (FD_ISSET(STDIN_FILENO, &fds)) {
            while ((buff[n++] = getchar()) != '\n');
            if (valid(self, buff) == True) {
                buff = phase_purge(buff, '"', EMPTY);
                send_client(self, buff);
            }
        } else if (FD_ISSET(master, &fds))
            parse_event(master, self);
    }
}
