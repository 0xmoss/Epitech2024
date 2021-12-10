/*
** EPITECH PROJECT, 2020
** teams
** File description:
** launch.c
*/

#include "tools.h"
#include "cli.h"

static int socket_create()
{
    int master = 0;

    printf("[  ....  ] creating socket\n");
    master = socket(AF_INET, SOCK_STREAM, 0);
    if (master < 0) {
        printf("[  FAIL  ] socket creation failed\n");
    } else {
        printf("[  DONE  ] socket created\n");
    }

    return (master);
}

static int socket_connect(int master, struct sockaddr_in addr)
{
    int status = 0;

    printf("[  ....  ] connecting to socket\n");
    status = connect(master, (struct sockaddr *)&addr, sizeof(addr));
    if (status < 0) {
        printf("[  FAIL  ] socket connection failed\n");
        exit(-1);
    } else {
        printf("[  DONE  ] connected to socket\n");
    }

    return (status);
}

int launch(char *ip, int port)
{
    int status = 0;
    self_t *s_client = build();
    struct hostent *info;
    struct sockaddr_in addr = {
        .sin_addr.s_addr = inet_addr(ip),
        .sin_family = AF_INET,
        .sin_port = htons(port)
    };
    int master = socket_create();
    int connection = socket_connect(master, addr);

    if (master >= 0 && connection >= 0) {
        input(master, s_client);
        free(s_client);
    }

    return (0);
}
