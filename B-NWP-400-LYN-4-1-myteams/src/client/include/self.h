/*
** EPITECH PROJECT, 2020
** teams
** File description:
** self.h
*/

#ifndef SELF_H
    #define SELF_H

    #include <uuid/uuid.h>

    #define CONNECTED 0
    #define DISCONNECTED -1

    #define BUFFER 1024

    typedef struct s_self
    {
        int login;
        uuid_t cli_uuid;
        int master;

        char **all;

        char *command;
        char *name;
        char *body;
        char *description;

        char *uid0;
        char *uid1;
        char *uid2;

        int use;
    } self_t;

    self_t *build();

#endif /* SELF_H */
