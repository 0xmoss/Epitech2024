/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** socket.c
*/

#include "socket.h"

#include "phaseout.h"

#include "build.h"
#include "input.h"
#include "send.h"

size_t binder(self_t *self, server_t *server, struct sockaddr_in client)
{
    server->bind = bind(server->socket,
        (struct sockaddr *)&client, sizeof(client));
    if (server->bind == -1) {
        printf("socket bind failed\n");
        return (False);
    }
    return (True);
}

size_t listenner(server_t *server)
{
    if (listen(server->socket, server->limit) == -1) {
        printf("socket listen failed\n");
        return (False);
    }
    printf("Listenning...\n");
    return (True);
}

size_t run(self_t *self, server_t *server)
{
    pid_t child = 0;

    for (size_t launched = True; launched == True; ) {
        accept_socket(self, server);
        child = fork();
        if (child == -1)
            close(server->guard);
        if (child == 0) {
            while (input(self, server) != False);
            close(server->socket);
            exit(False);
        }
    }

    return (True);
}

size_t accept_socket(self_t *self, server_t *server)
{
    struct sockaddr_in client;
    socklen_t len = sizeof(client);

    server->guard = accept(server->socket, (struct sockaddr *)&client,
        &len);
    if (server->guard == -1) {
        printf("Connection refused\n");
        return (False);
    }
    printf("Connection etablished\n");
    send_to_client(server, "220\n");
    return (True);
}

size_t create(self_t *self, server_t *server)
{
    struct sockaddr_in client;

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = htons((uint16_t)atoi(self->port));
    server->socket = socket(server->domain, server->type, server->protocol);
    if (server->socket != -1) {
        if (binder(self, server, client) == True && listenner(server) == True) {
            run(self, server);
            close(server->socket);
            return (True);
        }
        return (False);
    }
    printf("socket creation failed\n");
    return (False);
}
