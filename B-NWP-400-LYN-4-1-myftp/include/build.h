/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** build.h
*/

#ifndef SELF_H
    #define SELF_H

    #include "phaseout.h"

    typedef struct self_s
    {
        size_t s_port;
        size_t s_path;
        size_t s_help;
        char *port;
        char *path;
        size_t max;
    } self_t;

    self_t *build_self(void);

#endif /* SELF_H */

#ifndef SERVER_H
    #define SERVER_H

    #include "phaseout.h"

    typedef struct server_s
    {
        int protocol;
        int type;
        int domain;
        int limit;
        int bind;
        int socket;
        int guard;
        char *user;
        char *pass;
        size_t active;
        size_t passive;
    } server_t;

    server_t *build_server(void);

#endif /* SERVER_H */

#ifndef COMMANDS_H
    #define COMMANDS_H

    typedef struct commands_s
    {
        size_t (*command)(server_t *server, char **arguments);
    } commands_t;

#endif /* COMMANDS_H */
