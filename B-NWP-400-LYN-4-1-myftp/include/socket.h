/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** socket.h
*/

#ifndef SETTINGS_H
    #define SETTINGS_H

    #include <string.h>

    // SOCKET
    #include <netdb.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <sys/types.h>

    #include "phaseout.h"

    #include "build.h"

    size_t binder(self_t *, server_t *, struct sockaddr_in);
    size_t listenner(server_t *);
    size_t accept_socket(self_t *, server_t *);
    size_t run(self_t *, server_t *);

    size_t create(self_t *, server_t *);

#endif /* SETTINGS_H */
