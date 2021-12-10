/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myftp-
** File description:
** input.h
*/

#include "build.h"

#include "phaseout.h"

#include "socket.h"

#ifndef COMMANDS_PARSER_H
    #define COMMANDS_PARSER_H

        size_t parse_input(self_t *, server_t *, char **);
        size_t input(self_t *, server_t *);
        size_t commands(server_t *, char **);
        size_t id(char *);

#endif /* COMMANDS_PARSER_H */
