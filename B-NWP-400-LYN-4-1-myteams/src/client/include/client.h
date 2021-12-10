/*
** EPITECH PROJECT, 2020
** teams
** File description:
** client.h
*/

#ifndef CLIENT_H
    #define CLIENT_H

    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>

    #include "self.h"

    typedef void (*command)(char *, char **, self_t *, int);

    // HELP
    int help(int);

    // BUILD
    int launch(char *, int);
    int input(int, self_t *);
    int parse(int, self_t *);

    int parse_event(int, self_t *);

    void send_client(self_t *, char *);
    int start_client(char *, int);

#endif /* CLIENT_H */
