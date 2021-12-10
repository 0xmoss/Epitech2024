/*
** EPITECH PROJECT, 2020
** teams
** File description:
** help.c
*/

#include "client.h"

int help(int status)
{
    printf("USAGE: ./myteams_cli ip port\n\n");
    printf("\tip   is the server ip address on "
        "which the server socket listens.\n");
    printf("\tport is the port number on which the server socket listens\n");

    return (status);
}