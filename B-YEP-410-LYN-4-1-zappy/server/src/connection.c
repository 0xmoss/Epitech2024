/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** connection
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "struct.h"

ssize_t recv_data(int socket, char *dest, size_t max)
{
    size_t size = 0;
    char c;
    ssize_t ret;

    errno = 0;
    while (size < max && \
    (ret = recv(socket, &c, 1, MSG_DONTWAIT)) > 0 && c != '\0') {
        if (c == '\n')
            c = '\0';
        dest[size++] = c;
    }
    if ((ret <= 0 && errno != EAGAIN) || ret == 0)
        return -1;
    size -= 1;
    if (dest[size] != '\0')
        return 0;
    return size;
}

client_entry *new_client(int server_socket)
{
    client_entry *client;
    int socket_fd = accept(server_socket, NULL, NULL);

    if (socket_fd < 0)
        return NULL;
    if (send(socket_fd, "WELCOME\n", strlen("WELCOME\n"), 0) < 0)
        return NULL;
    client = malloc(sizeof(client_entry));
    client->data.client_socket = socket_fd;
    return client;
}