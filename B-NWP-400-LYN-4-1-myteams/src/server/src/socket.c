/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** socket
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include "define.h"
#include "struct.h"
#include "prototypes.h"

bool send_data_to_uuid(
    client_manager *manager, response_data data, uuid_t uuid, bool free_mode)
{
    struct client_entry *client = find_client_by_uuid(manager, uuid);

    if (client)
        return send_data_to_client(client, data, free_mode);
    return false;
}

bool send_data_to_name(
    client_manager *manager, response_data data,
    const char *name, bool free_mode)
{
    struct client_entry *client = find_client_by_name(manager, name);

    if (client)
        return send_data_to_client(client, data, free_mode);
    return false;
}

bool send_data_to_client(
    struct client_entry *client, response_data data, bool free_mode)
{
    char code[6];
    char size[11];

    if (client->data.client_socket == -1) {
        if (data.message != NULL && free_mode)
            free(data.message);
        return false;
    }
    sprintf(code, "%05u", data.code);
    sprintf(size, "%010lu", data.size);
    if (send(client->data.client_socket, code, 5, 0) != 5 ||
    send(client->data.client_socket, size, 10, 0) != 10 ||
    send(client->data.client_socket, data.message, data.size, 0)
    != (ssize_t) data.size) {
        if (data.message != NULL && free_mode)
            free(data.message);
        return false;
    }
    if (data.message != NULL && free_mode)
        free(data.message);
    return true;
}

int init_server(u_int16_t port)
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    struct sockaddr_in addr = {
        .sin_addr.s_addr = INADDR_ANY,
        .sin_family = AF_INET,
        .sin_port = htons(port)
    };

    if (socket_fd < 0) {
        return -1;
    }
    if (bind(socket_fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        close(socket_fd);
        return -1;
    }
    if (listen(socket_fd, SOMAXCONN) < 0) {
        close(socket_fd);
        return -1;
    }
    return socket_fd;
}